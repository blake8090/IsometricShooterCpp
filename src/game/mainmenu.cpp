#include "engine.h"
#include "mainmenu.h"

#include <fmt/core.h>
#include <raylib.h>

void MainMenuState::start() {
    fmt::println("[MainMenuState] INFO: start!");

    const int id = engine_.world->add_actor({ 0.0f, 0.0f, 0.0f });
    const auto actor = engine_.world->get_actor(id);

    const auto sprite = new Sprite{
        "assets/bullet.png",
        { 0.0f, 0.0f },
        1.0f,
        0.0f,
        0.0f
    };
    actor->set_sprite(std::unique_ptr<Sprite>(sprite));
    actor->set_collider(std::make_unique<Collider>(Vector3 {1.0f, 1.0f, 1.0f}, Vector3 {0.0f, 0.0f, 0.0f}));
}

void MainMenuState::stop() {
    fmt::println("[MainMenuState] INFO: stop!");
}

void MainMenuState::update(const float delta) {
    constexpr float speed = 1.25f;
    x += delta * speed;
    engine_.renderer->draw_texture("assets/bullet.png", { x, 0.0, 0.0 });

    engine_.renderer->draw_circle(Vector3{ 0.0f, 0.0f, 0.0f }, 1.0f, BLUE);

    const Box test_box{ Vector3{ 1.0f, 1.0f, 0.25f }, Vector3{ 1.0f, 1.0f, 1.5f } };
    engine_.renderer->draw_box(test_box, 1.0f, BLUE);
}
