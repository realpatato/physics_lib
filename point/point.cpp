#include "point.hpp"
#include "constants.hpp"

const int half_screen_width = constants::screen_width / 2;
const int half_screen_height = constants::screen_height / 2;

Point::Point(float x, float y) : 
    x(x), y(y), 
    draw_x(x + half_screen_width), draw_y(half_screen_height - y) 
{}
Point::Point() : x(0), y(0), draw_x(half_screen_width), draw_y(half_screen_height) {}

float Point::get_x() {
    return x;
}

float Point::get_y() {
    return y;
}

float Point::get_draw_x() {
    return draw_x;
}

float Point::get_draw_y() {
    return draw_y;
}