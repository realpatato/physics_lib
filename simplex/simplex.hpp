#pragma once
#include "point.hpp"

class Simplex {
    private:
        Point points[3];
        bool exists;
    public:
        Simplex(bool e);
        Simplex(Point (&ps)[3]);
};