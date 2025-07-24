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

void MainMenuState::update(float delta) {
	Texture2D bullet = engine.assets->get_texture("assets/bullet.png");
	DrawTexture(bullet, 300, 300, WHITE);
}
