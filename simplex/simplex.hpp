#pragma once
#include "point.hpp"

#include <raylib.h>
#include <vector>

class Simplex {
    private:
        std::vector<Point> points;
        std::vector<Vector2> draw_points;
        bool exists;
    public:
        Simplex(bool e);
        Simplex(std::vector<Point> ps);
        std::vector<Vector2> get_draw_points(std::vector<Point> ps);
        bool get_exists();
        void draw_self();
};