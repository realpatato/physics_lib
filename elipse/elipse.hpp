#pragma once
#include "point.hpp"
#include "simplex.hpp"

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
        Point get_direction(Elipse o);
        Point get_direction(Point sp1, Point sp2);
        Point get_first_simplex_point(Elipse o);
        Point get_simplex_point(Point d, Elipse o);
        Simplex get_simplex(Elipse o);
        void draw_self();
};