#pragma once
#include "point.hpp"

class Elipse {
    private:
        Point center;
        float h_rad;
        float v_rad;
    public:
        Elipse(Point c, float h, float v);
        Elipse(Point c, float r);
        Elipse(Point c);
        void draw_self();
};