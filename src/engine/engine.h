#pragma once

#include "assets.h"
#include "renderer.h"
#include "state.h"

#include <memory>
#include <string>

class Engine {
public:
    Engine() {
        running_ = false;
        assets = std::make_unique<Assets>();
        renderer = std::make_unique<Renderer>(*this);
    }

    void start(const std::string& window_title);

    void stop();

    void update();

    void shutdown();

    void set_state(State *state);

    bool running() const;

    std::unique_ptr<Assets> assets;
    std::unique_ptr<Renderer> renderer;

private:
    std::string windowTitle;

    std::unique_ptr<State> current_state;

    bool running_;
};
