#include "assets.h"

// fixes issue when building with CLion
#define FMT_HEADER_ONLY

#include <fmt/core.h>
#include <memory>
#include <raylib.h>

void Assets::init() {
    load_texture("assets/bullet.png");
}

void Assets::shutdown() {
    fmt::println("[Assets] INFO: Shutting down");
    for (const auto& [name, texture]: textures) {
        UnloadTexture(*texture);
        fmt::println("[Assets] INFO: Unloaded texture {}", name);
    }
}

Texture2D& Assets::get_texture(const std::string& name) {
    return *textures[name];
}

void Assets::load_texture(const std::string& fileName) {
    Texture2D texture = LoadTexture(fileName.c_str());
    textures.emplace(fileName, std::make_unique<Texture2D>(texture));
}
