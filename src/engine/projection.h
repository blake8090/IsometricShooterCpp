#pragma once

#include <raylib.h>

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
float get_isometric_ratio();

Vector2 to_screen(float x, float y, float z);

Vector2 to_screen(const Vector3& worldPos);

Vector3 to_world(const Vector2& screenPos);
}
