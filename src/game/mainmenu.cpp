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
}
