#include "assets.h"

#include <fmt/core.h>
#include <raylib.h>

void Assets::start() {
	load_texture("assets/bullet.png");
}

void Assets::shutdown() {
	fmt::println("[Assets] INFO: Shutting down");
	for (const auto& pair : textures) {
		UnloadTexture(pair.second);
	}
}

Texture2D Assets::get_texture(std::string name) {
	return textures[name];
}

void Assets::load_texture(std::string fileName) {
	Texture2D texture = LoadTexture(fileName.c_str());
	textures.emplace(fileName, texture);
}
