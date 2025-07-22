#pragma once

#include <fmt/core.h>
#include <raylib.h>

class Engine;

class State {
public:
	State(const Engine& e) : engine(e) {}

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void update(float delta) = 0;

protected:
	const Engine& engine;
};
