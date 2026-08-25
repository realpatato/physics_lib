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

    //non-touching
    Elipse e1 = Elipse(Point(-250, -125), 20, 20);
    Elipse e2 = Elipse(Point(250, -125), 20, 20);

    Point d1 = e1.get_direction(e2.get_center());
    Point sp1 = e1.support(d1);

    Point d2 = e2.get_direction(e1.get_center());
    Point sp2 = e2.support(d2);

    //touching
    Elipse e3 = Elipse(Point(-10, 125), 20, 20);
    Elipse e4 = Elipse(Point(10, 125), 20, 20);

    Point d3 = e3.get_direction(e4.get_center());
    Point sp3 = e3.support(d3);

    Point d4 = e4.get_direction(e3.get_center());
    Point sp4 = e4.support(d4);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawLine(screen_width/2, 0, screen_width/2, screen_height, BLACK);
            DrawLine(0, screen_height/2, screen_width, screen_height/2, BLACK);
            e1.draw_self();
            e2.draw_self();
            e3.draw_self();
            e4.draw_self();

            sp1.draw_self(); 
            sp2.draw_self();
            sp3.draw_self();
            sp4.draw_self();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}