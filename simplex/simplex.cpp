#include "point.hpp"
#include "simplex.hpp"

Simplex::Simplex(bool e) : exists(e) {};
Simplex::Simplex(Point (&ps)[3]) {
    for (int i = 0; i < 3; i++) {
        points[i] = ps[i];
    }
    exists = true;
};

bool Simplex::get_exists() {
    return exists;
}