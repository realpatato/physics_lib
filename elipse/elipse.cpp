#include "elipse.hpp"
#include "point.hpp"
#include "simplex.hpp"

#include <iostream>

#include <cmath>
#include <array>
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

Point Elipse::triple_product(Point a, Point b, Point c) {
    return b * (a * c) - a * (b * c); //dot products in parenthesis, vector multiplication, then point subtraction
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

Point Elipse::get_first_simplex_point(Elipse o) {
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

Point Elipse::get_simplex_point(Point d, Elipse o) {
    Point self_direction = d;
    Point self_support = this-> support(self_direction);
    
    Point other_direction = self_direction * -1;
    Point other_support = o.support(other_direction);

    Point simplex_support = self_support - other_support;

    return simplex_support;
}

bool Elipse::update_simplex(Point& a, Point& b, Point& c, int& smpx_size, Point& d, Elipse o) {
    if (smpx_size == 1) {
        b = a;
        a = get_simplex_point(d, o);
        //sanity check
        if (a * d < 0) {
            return true;
        }
        smpx_size++;
        d = triple_product(b - a, a * -1, b - a);
        return false;
    }

    if (smpx_size == 2) {
        c = b;
        b = a;
        a = get_simplex_point(d, o);
        //sanity check
        if (a * d < 0) {
            return true;
        }
        //origin checks
        //Region AB
        Point ab_perpendicular = triple_product(c - a, b - a, b - a);
        if (ab_perpendicular * (a * -1) > 0) {
            d = ab_perpendicular;
            return false;
        }
        //Region AC
        Point ac_perpendicular = triple_product(b - a, c - a, c - a);
        if (ac_perpendicular * (a * -1) > 0) {
            d = ac_perpendicular;
            b = c;
            return false;
        }
        smpx_size++;
        return true;
    }
}

Simplex Elipse::get_simplex(Elipse o) {
    Point sp1 = get_first_simplex_point(o);
    Point sp2 = Point(0, 0);
    Point sp3 = Point(0, 0);
    Point direction = Point(-sp1.get_x(), -sp1.get_y());
    int simplex_size = 1;

    bool found = update_simplex(sp1, sp2, sp3, simplex_size, direction, o);

    while (!found) {
        found = update_simplex(sp1, sp2, sp3, simplex_size, direction, o);
    }

    if (simplex_size < 3) {
        return Simplex(false);
    }
    return Simplex({sp1, sp2, sp3});
}