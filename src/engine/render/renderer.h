#pragma once
#include <raylib.h>
#include <string>
#include <vector>

#include "../actor.h"
#include "../box.h"
#include "shapes.h"

namespace engine {

class Engine;

struct TextureRenderable {
    std::string texture_name;
    Vector3 world_pos;
};

class Renderer {
public:
    explicit Renderer(const Engine& e) : engine_(e) {}

    void init(const std::string& window_title);
    void shutdown() const;
    void render();

    void draw_texture(const std::string& texture, Vector3 world_pos);
    void draw_circle(Vector3 pos, float radius, Color color);
    void draw_line(Vector3 start, Vector3 end, float width, Color color);
    void draw_box(const Box& box, float width, Color color);

    static bool window_closed();

private:
    const Engine& engine_;

    const int virtual_width_ = 960;
    const int virtual_height_ = 540;
    RenderTexture2D fbo_{};

    Camera2D camera_{};

    std::vector<TextureRenderable> textures_;
    Shapes shapes_{};

    static void draw_grid(int width, int length);
    void draw_textures();
    void draw_shapes();
    void draw_actors();
    void draw_sprite(const Sprite& sprite, const Vector3& world_pos) const;
};

};
