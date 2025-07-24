#include "renderer.h"

#include <raylib.h>

void Renderer::init(const std::string &windowTitle) {
    InitWindow(1920, 1080, windowTitle.c_str());
    SetTargetFPS(60);
}

void Renderer::shutdown() {
    CloseWindow();
}

void Renderer::render() {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(0, 0, 15, WHITE);
    EndDrawing();
}

bool Renderer::window_closed() {
    return WindowShouldClose();
}
