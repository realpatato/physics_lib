#pragma once
#include "point.hpp"

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