#include "projection.h"

#include <cmath>

namespace projection {

float get_isometric_ratio() {
    return std::sqrt(static_cast<float>(TILE_SIZE_X) / static_cast<float>(TILE_SIZE_Y));
}

Vector2 to_screen(const float x, const float y, const float z) {
    // this code was originally written for LibGDX, whose coordinate system starts in the bottom-left corner of the screen.
    // raylib's system starts in the top-left corner, so we need to internally flip x and y to maintain consistency in rendering.
    const float tx = y;
    const float ty = x;

    constexpr float scaleX = TILE_SIZE_X / 2.0;
    constexpr float scaleY = TILE_SIZE_Y / 2.0;

    // we also have to flip the z-axis for Raylib's coordinate system
    const float height = z * TILE_SIZE_Z * -1;

    return Vector2((tx + ty) * scaleX, (ty - tx) * scaleY + height);
}

Vector2 to_screen(const Vector3& worldPos) {
    return to_screen(worldPos.x, worldPos.y, worldPos.z);
}

Vector3 to_world(const Vector2& screenPos) {
    constexpr float w = TILE_SIZE_X / 2.0;
    constexpr float h = TILE_SIZE_Y / 2.0;
    const float mapX = screenPos.x / w - screenPos.y / h;
    const float mapY = screenPos.y / h + screenPos.x / w;

    return Vector3(
        mapX / 2,
        mapY / 2,
        0.0
    );
}

}
