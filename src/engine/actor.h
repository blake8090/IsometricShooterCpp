#pragma once
#include <memory>
#include <raylib.h>
#include <string>

struct Sprite {
    std::string texture;
    Vector2 offset;
    float alpha;
    float scale;
    float rotation;
};

struct Collider {
    Vector3 size;
    Vector3 offset;
};

class Actor {
public:
    Actor(const int i, const Vector3 pos) : id(i), pos(pos) {
    }

    int id;
    Vector3 pos;

    void set_sprite(std::unique_ptr<Sprite> sprite);

    Sprite* get_sprite() const;

    void set_collider(std::unique_ptr<Collider> collider);

    Collider* get_collider() const;

private:
    std::unique_ptr<Sprite> sprite_;
    std::unique_ptr<Collider> collider_;
};
