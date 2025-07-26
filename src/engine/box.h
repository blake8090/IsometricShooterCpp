#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "render/shapes.h"

namespace engine {

class Box {
public:
    Box(const Vector3& pos, const Vector3& size)
        : pos(pos), size(size) {}

    Vector3 pos;
    Vector3 size;

    [[nodiscard]] std::vector<Segment> get_segments() const;

    static Box from_min_max(const Vector3& min, const Vector3& max);

private:
    Vector3 min_{
        pos.x - (size.x / 2.0f),
        pos.y - (size.y / 2.0f),
        pos.z - (size.z / 2.0f)
    };

    Vector3 max_{
        pos.x + (size.x / 2.0f),
        pos.y + (size.y / 2.0f),
        pos.z + (size.z / 2.0f)
    };
};

// TODO: make this "generate_segments()" to avoid recalculating all this
//  also this shouldn't be inline
inline std::vector<Segment> Box::get_segments() const {
    std::vector<Segment> segments;
    // top
    segments.push_back(Segment(Vector3(min_.x, min_.y, max_.z), Vector3(min_.x, max_.y, max_.z)));
    segments.push_back(Segment(Vector3(min_.x, max_.y, max_.z), Vector3(max_.x, max_.y, max_.z)));
    segments.push_back(Segment(Vector3(max_.x, max_.y, max_.z), Vector3(max_.x, min_.y, max_.z)));
    segments.push_back(Segment(Vector3(max_.x, min_.y, max_.z), Vector3(min_.x, min_.y, max_.z)));

    // bottom
    segments.push_back(Segment(Vector3(min_.x, min_.y, min_.z), Vector3(min_.x, max_.y, min_.z)));
    segments.push_back(Segment(Vector3(min_.x, max_.y, min_.z), Vector3(max_.x, max_.y, min_.z)));
    segments.push_back(Segment(Vector3(max_.x, max_.y, min_.z), Vector3(max_.x, min_.y, min_.z)));
    segments.push_back(Segment(Vector3(max_.x, min_.y, min_.z), Vector3(min_.x, min_.y, min_.z)));

    // corners
    segments.push_back(Segment(Vector3(min_.x, min_.y, min_.z), Vector3(min_.x, min_.y, max_.z)));
    segments.push_back(Segment(Vector3(max_.x, min_.y, min_.z), Vector3(max_.x, min_.y, max_.z)));
    segments.push_back(Segment(Vector3(min_.x, max_.y, min_.z), Vector3(min_.x, max_.y, max_.z)));
    segments.push_back(Segment(Vector3(max_.x, max_.y, min_.z), Vector3(max_.x, max_.y, max_.z)));

    return segments;
}

// TODO: doesn't need to be inline
inline Box Box::from_min_max(const Vector3& min, const Vector3& max) {
    const Vector3 size = Vector3Subtract(max, min);
    const Vector3 scaledSize = Vector3Scale(size, 0.5f);
    const Vector3 center = Vector3Add(min, scaledSize);
    return { center, size };
}

};
