#include <iostream>
#include <string>
#include <raylib.h>

#include "point.hpp"
#include "elipse.hpp"
#include "constants.hpp"

int main() {
    const int screen_width = constants::screen_width;
    const int screen_height = constants::screen_height;

    InitWindow(screen_width, screen_height, "basic window");

    Point p = Point(0, 0);
    Point p2 = Point(10, 10);

    Point p3 = p + p2;
    Point p4 = p - p2;

    //non-touching
    Elipse e1 = Elipse(Point(-250, -125), 20, 20);
    Elipse e2 = Elipse(Point(250, -125), 20, 20);

    //touching
    Elipse e3 = Elipse(Point(-10, 125), 20, 20);
    Elipse e4 = Elipse(Point(10, 125), 20, 20);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawLine(screen_width/2, 0, screen_width/2, screen_height, BLACK);
            DrawLine(0, screen_height/2, screen_width, screen_height/2, BLACK);
            e1.draw_self();
            e2.draw_self();
            e3.draw_self();
            e4.draw_self();

            p3.draw_self(); 
            p4.draw_self();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}