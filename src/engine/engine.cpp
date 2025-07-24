#include "engine.h"
#include "renderer.h"

#include <memory>
#include <raylib.h>

void Engine::start(const std::string& windowTitle) {
	renderer->init(windowTitle);
	assets->init();

	running = true;
}

void Engine::stop() {
	running = false;
}

void Engine::update() {
	if (Renderer::window_closed()) {
		stop();
		return;
	}

	if (current_state) {
		current_state->update(GetFrameTime());
	}

	renderer->render();
}

void Engine::shutdown() {
	if (current_state) {
		current_state->stop();
	}

	assets->shutdown();
	Renderer::shutdown();
	running = false;
}

void Engine::set_state(State* state) {
	if (current_state) {
		current_state->stop();
	}

	state->start();
	current_state = std::unique_ptr<State>(state);
}

bool Engine::is_running() const {
	return running;
}
