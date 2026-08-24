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

    Elipse e = Elipse(Point(500, 250), 100, 100);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            e.draw_self();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}