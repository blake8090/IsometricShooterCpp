#pragma once
#include <raylib.h>
#include <vector>

struct Line3D {
    Vector3 start;
    Vector3 end;
    float width;
    Color color;
};

struct Circle3D {
    Vector3 pos;
    float radius;
    Color color;
};

struct Point3D {
    Vector3 pos;
    float size;
    Color color;
};

struct Sphere3D {
    Vector3 pos;
    float radius;
    Color color;
};

struct Shapes {
    std::vector<Line3D> lines;
    std::vector<Circle3D> circles;
    std::vector<Point3D> points;
    std::vector<Sphere3D> spheres;

    void clear() {
        lines.clear();
        circles.clear();
        points.clear();
        spheres.clear();
    }
};
