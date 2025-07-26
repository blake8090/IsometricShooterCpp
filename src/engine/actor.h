#pragma once
#include <memory>
#include <raylib.h>
#include <string>
#include <typeindex>
#include <unordered_map>
#include <utility>

namespace engine {

struct Component {};

struct Sprite : Component {
    std::string texture;
    Vector2 offset;
    float alpha;
    float scale;
    float rotation;

    explicit Sprite(
        std::string texture = "",
        const Vector2 offset = Vector2{},
        const float alpha = 0.0f,
        const float scale = 0.0f,
        const float rotation = 0.0f
    ) : texture(std::move(texture)),
        offset(offset),
        alpha(alpha),
        scale(scale),
        rotation(rotation) {}
};

struct Collider : Component {
    Vector3 size;
    Vector3 offset;

    explicit Collider(
        const Vector3 size = {},
        const Vector3 offset = {}
    ) : size(size), offset(offset) {}
};

class Actor {
public:
    Actor(const int i, const Vector3 pos) : id(i), pos(pos) {}

    int id;
    Vector3 pos;

    template<typename T, typename... Args>
    void add_component(Args&&... args) {
        static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");
        components_[std::type_index(typeid(T))] = std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    T* get_component() {
        static_assert(std::is_base_of_v<Component, T>, "T must derive from Component");

        const std::type_index type_index(typeid(T));
        if (const auto it = components_.find(type_index); it != components_.end()) {
            return static_cast<T *>(it->second.get());
        }

        return nullptr;
    }

private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components_;
};

};
