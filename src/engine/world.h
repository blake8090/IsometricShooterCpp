#pragma once
#include <functional>
#include <memory>
#include <unordered_map>

#include "actor.h"

namespace engine {

class World {
public:
    int add_actor(Vector3 pos);
    Actor* get_actor(int id);
    void each_actor(const std::function<void(Actor&)>& func);

private:
    int next_id = 0;
    std::unordered_map<int, std::unique_ptr<Actor>> actors_;
};

};
