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
        Point operator+(const Point& other);
        Point operator-(const Point& other);
        Point operator*(const float& other);
        float operator*(const Point& other); //dot product
        float get_x();
        void mod_x(float nx);
        float get_y();
        void mod_y(float ny);
        float get_draw_x();
        float get_draw_y();
        void draw_self();
};