#pragma once

#include "engine.h"
#include "state.h"

class MainMenuState : public State {
public:
	MainMenuState(const Engine& e) : State(e) {}

	void start() override;
	void stop() override;
	void update(float delta) override;
};
