#pragma once

#include <cmath>
#include <raymath.h>

namespace projection {

/**
 * Width of one tile in pixels
 */
constexpr int TILE_SIZE_X = 64;

/**
 * Length of one tile in pixels
 */
constexpr int TILE_SIZE_Y = 32;

/**
 * Height of one tile in pixels
 */
constexpr int TILE_SIZE_Z = 32;

/**
 * Two to one ratio (64/32 = 2)
 */
constexpr float get_isometric_ratio() {
    return std::sqrt(static_cast<float>(TILE_SIZE_X) / static_cast<float>(TILE_SIZE_Y));
}

Vector2 to_screen(float x, float y, float z);
Vector2 to_screen(const Vector3& worldPos);

Vector3 to_world(const Vector2& screenPos, float offset = 0.0f);

}
