#pragma once
#include <raylib.h>
#include <string>

class Engine;

class Renderer {
public:
    explicit Renderer(const Engine& e) : engine_(e) {}

    void init(const std::string& window_title);
    void shutdown() const;
    void render() const;

    static bool window_closed();

private:
    const Engine& engine_;

    const int virtual_width_ = 960;
    const int virtual_height_ = 540;
    RenderTexture2D fbo_{};

    Camera2D camera_{};

    static void draw_grid(int width, int length);
};
