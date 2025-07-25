#include "engine.h"
#include "renderer.h"

#include <memory>
#include <raylib.h>

void Engine::start(const std::string& window_title) {
    renderer->init(window_title);
    assets->init();

    running_ = true;
}

void Engine::stop() {
    running_ = false;
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
    renderer->shutdown();
    running_ = false;
}

void Engine::set_state(State *state) {
    if (current_state) {
        current_state->stop();
    }

    state->start();
    current_state = std::unique_ptr<State>(state);
}

bool Engine::running() const {
    return running_;
}
