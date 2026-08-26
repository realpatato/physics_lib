#include "elipse.hpp"
#include "point.hpp"
#include "simplex.hpp"

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

Point Elipse::get_direction(Elipse o) {
    return (center - o.get_center());
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
    Point self_direction = this-> get_direction(o);
    Point self_support = this-> support(self_direction);

    //support point of other shape
    Point other_direction = self_direction * -1;
    Point other_support = o.support(other_direction);

    //get the support point made by the difference
    Point simplex_support = self_support - other_support;
    return simplex_support;
}

Point Elipse::get_simplex_point2(Point d, Elipse o) {
    Point self_direction = d;
    Point self_support = this-> support(self_direction);
    
    Point other_direction = self_direction * -1;
    Point other_support = o.support(other_direction);

    Point simplex_support = self_support - other_support;

    return simplex_support;
}

Simplex Elipse::get_simplex(Elipse o) {
    Point sp1 = get_simplex_point1(o);

    Point sp2d = Point(0, 0) - sp1;
    Point sp2 = get_simplex_point2(sp2d, o);
    
    //sanitity check
    if ((sp2d * sp2) < 0) {
        return Simplex(false);
    }
}