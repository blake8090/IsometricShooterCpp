#include "engine.h"
#include "mainmenu.h"

#include <fmt/core.h>
#include <raylib.h>

void MainMenuState::start() {
    fmt::println("[MainMenuState] INFO: start!");
}

void MainMenuState::stop() {
    fmt::println("[MainMenuState] INFO: stop!");
}

void MainMenuState::update(const float delta) {
    constexpr float speed = 1.25f;
    x += delta * speed;
    engine_.renderer->draw_texture("assets/bullet.png", { x, 0.0, 0.0 });

    engine_.renderer->draw_circle(Vector3{ 0.0f, 0.0f, 0.0f }, 1.0f, BLUE);

    const Box b{Vector3{4.0f, 0.0f, 0.0f}, Vector3{1.0f, 1.0f, 1.5f}};
    engine_.renderer->draw_box(b, 1.0f, BLUE);
}
