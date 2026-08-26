#include "elipse.hpp"
#include "point.hpp"

#include <cmath>
#include <raylib.h>

Elipse::Elipse(Point c, float h, float v) : center(c), h_rad(h), v_rad(v) {}
Elipse::Elipse(Point c, float r) : Elipse(c, r, r) {}
Elipse::Elipse(Point c) : Elipse(c, 50, 50) {}

Point Elipse::get_center() {
    return center;
}

void Elipse::draw_self() {
    DrawEllipse((int) center.get_draw_x(), center.get_draw_y(), h_rad, v_rad, RED);
}

Point Elipse::get_direction(Elipse e) {
    return (center - e.get_center());
}

Point Elipse::support(Point d) {
    Point p = Point();

    float h_sqd = h_rad * h_rad;
    float v_sqd = v_rad * v_rad;

    float d_x = d.get_x();
    float d_y = d.get_y();

    float inside_sqrt = h_sqd * (d_x * d_x) + v_sqd * (d_y * d_y);
    float denom = std::sqrt(inside_sqrt);

    if (denom == 0) {
        return Point();
    }

    p.mod_x(h_sqd * d_x / denom);
    p.mod_y(v_sqd * d_y / denom);
    return p + center;
}

Point Elipse::get_simplex_point1(Elipse o) {
    //support point towards other shape
    Point other_direction = this-> get_direction(o);
    Point self_support = this-> support(other_direction);

    //support point of other shape
    Point self_direction = o.get_direction(*this);
    Point other_support = o.support(self_direction);

    //get the support point made by the difference
    Point simplex_support = self_support - other_support;
    return simplex_support;
}