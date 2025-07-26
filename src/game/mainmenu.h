#pragma once

#include "state.h"

class MainMenuState final : public engine::State {
public:
    explicit MainMenuState(const engine::Engine& e) : engine::State(e) {
    }

    void start() override;

    void stop() override;

    void update(float delta) override;

private:
    float x = 0.0;
};
