#pragma once

#include "assets.h"
#include "state.h"

#include <iostream>
#include <memory>
#include <string>

class Engine {

public:
	Engine(std::string title) {
		windowTitle = title;
		running = false;
		assets = std::make_unique<Assets>();
	}

	void start();
	void stop();
	void update();
	void shutdown();

	void set_state(State* state);

	bool is_running() const;

	std::unique_ptr<Assets> assets;

private:
	std::string windowTitle;

	std::unique_ptr<State> current_state;
	
	bool running;
};
