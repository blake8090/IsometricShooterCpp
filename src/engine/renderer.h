#pragma once
#include <string>

class Engine;

class Renderer {
public:
    explicit Renderer(const Engine& e) : engine(e) {}
    virtual ~Renderer() = default;

    static void init(const std::string& windowTitle);
    static void shutdown();
    static void render();

    static bool window_closed();

private:
    const Engine& engine;
};
