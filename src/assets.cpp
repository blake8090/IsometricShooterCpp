#include "assets.h"

#include <fmt/core.h>
#include <memory>
#include <raylib.h>

void Assets::start() {
	load_texture("assets/bullet.png");
}

void Assets::shutdown() {
	fmt::println("[Assets] INFO: Shutting down");
	for (const auto& pair : textures) {
		UnloadTexture(*pair.second);
		fmt::println("[Assets] INFO: Unloaded texture {}", pair.first);
	}
}

Texture2D& Assets::get_texture(std::string name) {
	return *textures[name];
}

void Assets::load_texture(std::string fileName) {
	Texture2D texture = LoadTexture(fileName.c_str());
	textures.emplace(fileName, std::make_unique<Texture2D>(texture));
}
