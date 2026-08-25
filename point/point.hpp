#pragma once

class Point {
    private:
        float x;
        float y;
        float draw_x;
        float draw_y;
    public:
        Point(float x, float y);
        Point();
        float get_x();
        float get_y();
        float get_draw_x();
        float get_draw_y();
};