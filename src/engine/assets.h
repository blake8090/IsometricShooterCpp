#pragma once

#include <iostream>
#include <memory>
#include <raylib.h>
#include <unordered_map>

namespace engine {

class Assets {
public:
    void init();
    void shutdown();

    bool has_texture(const std::string& name) const;
    Texture2D& get_texture(const std::string& name);

private:
    void load_texture(const std::string& fileName);

    std::unordered_map<std::string, std::unique_ptr<Texture2D>> textures;
};

};
