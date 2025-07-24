#pragma once

#include "state.h"

class MainMenuState final : public State {
public:
	explicit MainMenuState(const Engine& e) : State(e) {}

	void start() override;
	void stop() override;
	void update(float delta) override;

private:
	float x = 0.0;
};
