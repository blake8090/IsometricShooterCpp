#include <fmt/core.h>
#include <raylib.h>
#include "engine.h"

void Engine::start() {
	InitWindow(800, 600, "My first RAYLIB program!");
	SetTargetFPS(60);
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

	BeginDrawing();
	ClearBackground(BLACK);
	DrawCircle(0, 0, 15, WHITE);
	EndDrawing();
}

void Engine::shutdown() {
	CloseWindow();
	running = false;
}

bool Engine::is_running() const {
	return running;
}
