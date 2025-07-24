#include "projection.h"

namespace projection {

Vector2 to_screen(const float x, const float y, const float z) {
    constexpr float scaleX = TILE_SIZE_X / 2.0;
    constexpr float scaleY = TILE_SIZE_Y / 2.0;
    const float height = z * TILE_SIZE_Z;
    return Vector2((x + y) * scaleX, (y - x) * scaleY + height);
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
