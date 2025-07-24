#include "renderer.h"
#include "projection.h"

#include <raylib.h>

void Renderer::init(const std::string &windowTitle) {
    constexpr int virtual_width = 960;
    constexpr int virtual_height = 540;
    // TODO: render to a texture using virtual width/height and scale up to screen size
    InitWindow(virtual_width, virtual_height, windowTitle.c_str());
    SetTargetFPS(60);

    camera_.target = projection::to_screen(0.0, 0.0, 0.0);
    camera_.offset = {virtual_width * 0.5, virtual_height * 0.5 };
    camera_.zoom = 1.0;
}

void Renderer::shutdown() {
    CloseWindow();
}

void Renderer::render() const {
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode2D(camera_);
    DrawCircle(0, 0, 15, WHITE);
    draw_grid(20, 20);
    EndMode2D();

    EndDrawing();
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
