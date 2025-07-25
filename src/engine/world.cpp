#include "world.h"

#include <ranges>

int World::add_actor(Vector3 pos) {
    int id = next_id++;
    actors_.emplace(id, std::make_unique<Actor>(id, pos));
    return id;
}

Actor* World::get_actor(const int id) {
    if (const auto it = actors_.find(id); it != actors_.end()) {
        return it->second.get();
    }
    return nullptr;
}

void World::each_actor(const std::function<void(Actor&)>& func) {
    for (auto& val: actors_ | std::views::values) {
        func(*val.get());
    }
}
