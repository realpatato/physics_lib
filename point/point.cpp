#include "point.hpp"

Point::Point(float x, float y) : x(x), y(y) {}
Point::Point() : x(0), y(0) {}

float Point::get_x() {
    return x;
}

float Point::get_y() {
    return y;
}