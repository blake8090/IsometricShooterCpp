#pragma once

#include <iostream>
#include <map>
#include <raylib.h>
#include <unordered_map>

class Assets {

public:
	void start();
	void shutdown();

	Texture2D get_texture(std::string name);

private:
	void load_texture(std::string fileName);

	std::unordered_map<std::string, Texture2D> textures;
};
