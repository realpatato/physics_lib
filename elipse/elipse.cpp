#include "elipse.hpp"
#include "point.hpp"

#include <raylib.h>

Elipse::Elipse(Point c, float h, float v) : center(c), h_rad(h), v_rad(v) {}
Elipse::Elipse(Point c, float r) : Elipse(c, r, r) {}
Elipse::Elipse(Point c) : Elipse(c, 50, 50) {}

void Elipse::draw_self() {
    DrawEllipse((int) center.get_draw_x(), center.get_draw_y(), h_rad, v_rad, RED);
}