#include "point.hpp"
#include "simplex.hpp"

#include <raylib.h>
#include <iostream>
#include <vector>
#include <cmath>

Simplex::Simplex(bool e) : exists(e) {};
Simplex::Simplex(std::vector<Point> ps) {
    points = ps;
    draw_points = get_draw_points(ps);
    exists = true;
}

std::vector<Vector2> Simplex::get_draw_points(std::vector<Point> ps) {
    //create point array
    float x_total = 0;
    float y_total = 0;
    for (Point p : ps) {
        x_total += p.get_x();
        y_total += p.get_y();
    }
    Point center = Point(x_total / ps.size(), y_total / ps.size());

    std::vector<float> angles;
    std::vector<Point> dp = ps;

    //sort the points by draw angle measures, to enforce direction
    for (Point p : dp) {
        angles.push_back(std::atan2(p.get_draw_y() - center.get_draw_y(), p.get_draw_x() - center.get_draw_x()));
    }

    for (int i = 0; i < angles.size(); i++) {
        bool swapped = false;
        for (int k = 0; k < angles.size() - i - 1; k++) {
            if (angles[k] < angles[k + 1]) {
                float temp_a = angles[k + 1];
                angles[k + 1] = angles[k];
                angles[k] = temp_a;

                Point temp_p = dp[k + 1];
                dp[k + 1] = dp[k];
                dp[k] = temp_p;

                swapped = true;
            }
        }
        //early end to optimise (only needed for visualising algorithm so not that important)
        if (!swapped) {
            break;
        }
    }

    dp.push_back(dp.front());
    dp.insert(dp.begin(), center);

    //convert to vector2
    std::vector<Vector2> dpv2 = {};
    for (Point p : dp) {
        dpv2.push_back((Vector2)p);
    }
    return dpv2;
}

bool Simplex::get_exists() {
    return exists;
}

void Simplex::draw_self() {
    if (!exists) return;
    DrawTriangleFan(draw_points.data(), draw_points.size(), PURPLE);
}