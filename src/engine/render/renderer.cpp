#include "renderer.h"
#include "../projection.h"
#include "../actor.h"

#include <vector>
#include <raylib.h>

#include "../engine.h"

namespace engine {

void Renderer::init(const std::string& window_title) {
    // TODO: pass in window width/height from config loaded by the engine
    InitWindow(1920, 1080, window_title.c_str());
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    fbo_ = LoadRenderTexture(virtual_width_, virtual_height_);

    camera_.target = projection::to_screen(0.0, 0.0, 0.0);
    camera_.offset = { static_cast<float>(virtual_width_) * 0.5f, static_cast<float>(virtual_height_) * 0.5f };
    camera_.zoom = 1.0;
}

void Renderer::shutdown() const {
    UnloadRenderTexture(fbo_);
    CloseWindow();
}

void Renderer::render() {
    // draw game world to the fbo
    BeginTextureMode(fbo_);
    ClearBackground(BLACK);

    BeginMode2D(camera_);
    draw_grid(20, 20);
    draw_textures();
    draw_shapes();
    draw_actors();
    EndMode2D();

    EndTextureMode();

    // define what area of the fbo texture we'll draw - in this case, the entire texture
    const Rectangle source = {
        0.0f,
        0.0f,
        static_cast<float>(fbo_.texture.width),
        static_cast<float>(-fbo_.texture.height), // flip to match OpenGL coords which are inverted
    };

    // the fbo texture will be scaled and drawn to this area (the entire screen)
    constexpr Rectangle dest = { 0.0f, 0.0f, 1920.0f, 1080.0f };

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(fbo_.texture, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);
    DrawFPS(16, 16);
    EndDrawing();
}

void Renderer::draw_texture(const std::string& texture, const Vector3 world_pos) {
    textures_.emplace_back(TextureRenderable{ texture, world_pos });
}

void Renderer::draw_circle(const Vector3 pos, const float radius, const Color color) {
    shapes_.circles.push_back(Circle3D{ pos, radius, color });
}

void Renderer::draw_line(const Vector3 start, const Vector3 end, const float width, const Color color) {
    shapes_.lines.push_back(Line3D{ start, end, width, color });
}

void Renderer::draw_box(const Box& box, const float width, const Color color) {
    for (const auto& segment: box.get_segments()) {
        draw_line(segment.start, segment.end, width, color);
    }
}

bool Renderer::window_closed() {
    return WindowShouldClose();
}

void Renderer::draw_grid(int width, int length) {
    for (int x = 0; x <= width; x++) {
        Vector3 start(static_cast<float>(x), 0.0, 0.0);
        Vector3 end(static_cast<float>(x), static_cast<float>(length), 0.0);
        Vector2 screen_start = projection::to_screen(start);
        Vector2 screen_end = projection::to_screen(end);
        DrawLine(
            static_cast<int>(screen_start.x),
            static_cast<int>(screen_start.y),
            static_cast<int>(screen_end.x),
            static_cast<int>(screen_end.y),
            WHITE
        );
    }

    for (int y = 0; y <= length; y++) {
        Vector3 start(0, static_cast<float>(y), 0.0);
        Vector3 end(static_cast<float>(width), static_cast<float>(y), 0.0);
        Vector2 screen_start = projection::to_screen(start);
        Vector2 screen_end = projection::to_screen(end);
        DrawLine(
            static_cast<int>(screen_start.x),
            static_cast<int>(screen_start.y),
            static_cast<int>(screen_end.x),
            static_cast<int>(screen_end.y),
            WHITE
        );
    }
}

void Renderer::draw_textures() {
    for (const auto& [texture_name, world_pos]: textures_) {
        const auto screen_pos = projection::to_screen(world_pos);
        DrawTextureV(
            engine_.assets->get_texture(texture_name),
            screen_pos,
            WHITE
        );
    }
    textures_.clear();
}

void Renderer::draw_shapes() {
    for (const auto& line: shapes_.lines) {
        DrawLineEx(
            projection::to_screen(line.start),
            projection::to_screen(line.end),
            line.width,
            line.color
        );
    }

    for (const auto& circle: shapes_.circles) {
        const float ratio = projection::get_isometric_ratio();
        const float width = circle.radius * (projection::TILE_SIZE_X / 2.0f) * ratio;
        const float height = circle.radius * (projection::TILE_SIZE_Y / 2.0f) * ratio;
        auto [x, y] = projection::to_screen(Vector3{ 0.0f, 0.0f, 0.0f });

        DrawEllipseLines(
            static_cast<int>(x),
            static_cast<int>(y),
            width,
            height,
            circle.color
        );
    }

    for (const auto& point: shapes_.points) {
        DrawCircleV(
            projection::to_screen(point.pos),
            point.size,
            point.color
        );
    }

    shapes_.clear();
}

void Renderer::draw_actors() {
    engine_.world->each_actor([this](Actor& actor) {
        if (const Sprite* sprite = actor.get_component<Sprite>()) {
            draw_sprite(*sprite, actor.pos);
        }

        if (const Collider* collider = actor.get_component<Collider>()) {
            const Vector3 min = Vector3Add(actor.pos, collider->offset);
            const Vector3 max = Vector3Add(min, collider->size);
            const Box b = Box::from_min_max(min, max);
            this->draw_box(b, 1.0f, YELLOW);
        }
    });
}

void Renderer::draw_sprite(const Sprite& sprite, const Vector3& world_pos) const {
    if (engine_.assets->has_texture(sprite.texture)) {
        const Texture2D texture = engine_.assets->get_texture(sprite.texture);
        const auto screen_pos = projection::to_screen(world_pos);
        DrawTextureV(texture, screen_pos, WHITE);
    }
}

};
