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
        Point get_center();
        Point support(Point d);
        Point get_direction(Elipse e);
        Point get_simplex_point1(Elipse e);
        void draw_self();
};