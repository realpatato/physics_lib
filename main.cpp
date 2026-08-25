#include <iostream>
#include <string>
#include <raylib.h>

#include "point.hpp"
#include "elipse.hpp"

int main() {
    const int screen_width = 1000;
    const int screen_height = 500;

    InitWindow(screen_width, screen_height, "basic window");

    Point p = Point(0, 0);
    std::cout << p.get_x() << ", " << p.get_y() << std::endl; 

    //non-touching
    Elipse e1 = Elipse(Point(250, 125), 20, 20);
    Elipse e2 = Elipse(Point(750, 125), 20, 20);

    //touching
    Elipse e3 = Elipse(Point(490, 375), 20, 20);
    Elipse e4 = Elipse(Point(510, 375), 20, 20);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            e1.draw_self();
            e2.draw_self();
            e3.draw_self();
            e4.draw_self();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}