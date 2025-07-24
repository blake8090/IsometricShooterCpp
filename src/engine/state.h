#pragma once

class Engine;

class State {
public:
    explicit State(const Engine& e) : engine_(e) {
    }

    virtual ~State() = default;

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual void update(float delta) = 0;

protected:
    const Engine& engine_;
};
