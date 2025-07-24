#pragma once
#include <raylib.h>
#include <string>

class Engine;

class Renderer {
public:
    explicit Renderer(const Engine& e) : engine(e) {}
    virtual ~Renderer() = default;

    void init(const std::string& windowTitle);
    static void shutdown();
    void render() const;

    static bool window_closed();

private:
    const Engine& engine;

    Camera2D camera_{};

    static void draw_grid(int width, int length);
};
