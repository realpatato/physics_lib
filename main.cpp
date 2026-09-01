#include <iostream>
#include <string>
#include <raylib.h>

#include "point.hpp"
#include "shapes.hpp"
#include "constants.hpp"
#include "simplex.hpp"
#include "gjk.hpp"

int main() {
    const int screen_width = constants::screen_width;
    const int screen_height = constants::screen_height;

    InitWindow(screen_width, screen_height, "basic window");

    //non-touching
    Shape* e1 = new Ellipse(Point(-250, -125), 20, 20);
    Shape* e2 = new Ellipse(Point(250, -125), 20, 20);

    Simplex s = get_simplex(e1, e2);

    std::cout << s.get_exists() << std::endl;

    //touching
    Shape* e3 = new Ellipse(Point(-10, 125), 20, 20);
    Shape* e4 = new Ellipse(Point(10, 100), 20, 20);

    Simplex s2 = get_simplex(e3, e4);

    std::cout << s2.get_exists() << std::endl;

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawLine(screen_width/2, 0, screen_width/2, screen_height, BLACK);
            DrawLine(0, screen_height/2, screen_width, screen_height/2, BLACK);
            e1->draw_self();
            e2->draw_self();
            e3->draw_self();
            e4->draw_self();

            s2.draw_self();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}