#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <raylib.h>
#include <unordered_map>

class Assets {

public:
	void start();
	void shutdown();

	Texture2D& get_texture(const std::string& name);

private:
	void load_texture(const std::string& fileName);

	std::unordered_map<std::string, std::unique_ptr<Texture2D>> textures;
};
