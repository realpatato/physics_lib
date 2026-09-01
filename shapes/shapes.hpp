#pragma once

#include "point.hpp"

#include <vector>

class Shape {
    private: 
        Point center;
    public:
        virtual ~Shape() = default;
        virtual Point get_center();
        virtual Point support(Point d);

        virtual void draw_self();
};

class Ellipse : public Shape {
    private:
        Point center;
        float h_rad;
        float v_rad;
    public:
        Ellipse(Point c, float h, float v);
        Ellipse(Point c, float r);
        Ellipse(Point c);
        Point get_center() override;
        Point support(Point d) override;
        
        void draw_self() override;
};

class Polygon : public Shape {
    private:
        Point center;
        std::vector<Point> points;
        std::vector<Vector2> draw_points;
    public:
        Polygon(std::vector<Point> p);
        Point gen_center(std::vector<Point> p);
        Point get_center() override;
        Point support(Point d) override;
        std::vector<Point> gen_sorted_points(std::vector<Point> p, Point c);

        std::vector<Vector2> gen_draw_points(std::vector<Point> sp, Point c);
        void draw_self() override;
};