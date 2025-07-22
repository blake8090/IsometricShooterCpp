#pragma once

#include "engine.h"
#include "state.h"

class MainMenuState : public State {
public:
	MainMenuState(const Engine& e) : State(e) {}

	void start() {
		fmt::println("[MainMenuState] INFO: start!");
	}

	void stop() {
		fmt::println("[MainMenuState] INFO: stop!");
	}

	void update(float delta) {
		Texture2D bullet = engine.assets->get_texture("assets/bullet.png");
		DrawTexture(bullet, 300, 300, WHITE);
	}
};
