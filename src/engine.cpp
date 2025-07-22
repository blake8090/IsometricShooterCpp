#include "engine.h"

#include <fmt/core.h>
#include <memory>
#include <raylib.h>

void Engine::start() {
	InitWindow(1920, 1080, "My first RAYLIB program!");
	SetTargetFPS(60);

	assets->start();

	running = true;
}

void Engine::stop() {
	running = false;
}

void Engine::update() {
	if (WindowShouldClose()) {
		stop();
		return;
	}

	if (current_state) {
		current_state->update(GetFrameTime());
	}

	BeginDrawing();
	ClearBackground(BLACK);
	DrawCircle(0, 0, 15, WHITE);
	EndDrawing();
}

void Engine::shutdown() {
	if (current_state) {
		current_state->stop();
	}

	assets->shutdown();
	
	CloseWindow();
	running = false;
}

void Engine::set_state(State* state)
{
	if (current_state) {
		current_state->stop();
	}

	state->start();
	current_state = std::unique_ptr<State>(state);
}

bool Engine::is_running() const {
	return running;
}
