#include "point.hpp"
#include "shapes.hpp"

#include <cmath>
#include <iostream>
#include <raylib.h>

//shape class, kind of a default
Point Shape::get_center() {
    return Point(0, 0);
}
Point Shape::support(Point d) {
    return Point(0, 0);
}
void Shape::draw_self() {
    return;
}

//ellipse class
Ellipse::Ellipse(Point c, float h, float v) : center(c), h_rad(h), v_rad(v) {}
Ellipse::Ellipse(Point c, float r) : Ellipse(c, r, r) {}
Ellipse::Ellipse(Point c) : Ellipse(c, 50, 50) {}

Point Ellipse::get_center() {
    return center;
}

Point Ellipse::support(Point d) {
    Point p = Point();

    float h_sqd = h_rad * h_rad;
    float v_sqd = v_rad * v_rad;

    float d_x = d.get_x() / h_rad;
    float d_y = d.get_y() / v_rad;

    float inside_sqrt = h_sqd * (d_x * d_x) + v_sqd * (d_y * d_y);
    float denom = std::sqrt(inside_sqrt);

    if (denom == 0) {
        return Point(h_rad, 0);
    } 

    p.mod_x(h_sqd * d_x / denom);
    p.mod_y(v_sqd * d_y / denom);
    return p + center;
}

void Ellipse::draw_self() {
    DrawEllipse((int) center.get_draw_x(), center.get_draw_y(), h_rad, v_rad, RED);
}

Polygon::Polygon(std::vector<Point> p) : 
    center(gen_center(p)), 
    points(gen_sorted_points(p, center)), 
    draw_points(gen_draw_points(points, center)) 
{}

Point Polygon::gen_center(std::vector<Point> ps) {
    float x_total = 0;
    float y_total = 0;
    for (Point p : ps) {
        x_total += p.get_x();
        y_total += p.get_y();
    }
    return Point(x_total / ps.size(), y_total / ps.size());
}

std::vector<Point> Polygon::gen_sorted_points(std::vector<Point> ps, Point c) {
    std::vector<float> angles = {};
    std::vector<Point> rps = ps;
    //get angles respective to center
    for (Point p : ps) {
        angles.push_back(std::atan2(p.get_y() - c.get_y(), p.get_x() - c.get_x()));
    }
    //sort angles and points
    for (int i = 0; i < angles.size(); i++) {
        int max = 0;
        for (int k = 0; k < angles.size() - i; k++) {
            if (angles[k] > angles[max]) {
                max = k;
            }
        }

        int target = angles.size() - (i + 1);

        if (max != target) {

            float temp_a = angles[target];
            angles[target] = angles[max];
            angles[max] = temp_a;

            Point temp_p = rps[target];
            rps[target] = rps[max];
            rps[max] = temp_p;
        }
    }
    return rps;
}

std::vector<Vector2> Polygon::gen_draw_points(std::vector<Point> sp, Point c) {
    std::vector<Point> dp = sp;

    dp.push_back(dp.front());
    dp.insert(dp.begin(), center);

    //convert to vector2
    std::vector<Vector2> dpv2 = {};
    for (Point p : dp) {
        dpv2.push_back((Vector2)p);
    }
    return dpv2;
}

void Polygon::draw_self() {
    DrawTriangleFan(draw_points.data(), draw_points.size(), RED);
}