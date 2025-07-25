#include "actor.h"

#include <memory>

void Actor::set_sprite(std::unique_ptr<Sprite> sprite) {
    sprite_ = std::move(sprite);
}

Sprite* Actor::get_sprite() const {
    return sprite_.get();
}

void Actor::set_collider(std::unique_ptr<Collider> collider) {
    collider_ = std::move(collider);
}

Collider* Actor::get_collider() const {
    return collider_.get();
}
