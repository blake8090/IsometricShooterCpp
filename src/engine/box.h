#pragma once

#include <raylib.h>
#include <vector>

#include "shapes.h"

class Box {
public:
    Box(const Vector3& pos, const Vector3& size)
        : pos(pos), size(size) {
    }

    Vector3 pos;
    Vector3 size;

    [[nodiscard]] std::vector<Segment> get_segments() const;

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
