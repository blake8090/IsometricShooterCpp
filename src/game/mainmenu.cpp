#include "engine.h"
#include "mainmenu.h"
#include "actor.h"

#include <fmt/core.h>
#include <raylib.h>

void MainMenuState::start() {
    fmt::println("[MainMenuState] INFO: start!");

    const int id = engine_.world->add_actor({ 0.0f, 0.0f, 0.0f });
    const auto actor = engine_.world->get_actor(id);

    actor->add_component<engine::Sprite>("assets/cube.png");
    actor->add_component<engine::Collider>(Vector3{ 1.0f, 1.0f, 1.0f }, Vector3{ 0.0f, 0.0f, 0.0f });
}

void MainMenuState::stop() {
    fmt::println("[MainMenuState] INFO: stop!");
}

void MainMenuState::update(const float delta) {
    constexpr float speed = 1.25f;
    x += delta * speed;

    engine_.renderer->draw_circle(Vector3{ 0.0f, 0.0f, 0.0f }, 1.0f, BLUE);

    const engine::Box test_box{ Vector3{ 1.0f, 1.0f, 0.25f }, Vector3{ 1.0f, 1.0f, 1.5f } };
    engine_.renderer->draw_box(test_box, 1.0f, BLUE);
}
