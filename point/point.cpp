#include "point.hpp"

Point::Point(float x, float y) : x(x), y(y) {}

float Point::get_x() {
    return x;
}

float Point::get_y() {
    return y;
}