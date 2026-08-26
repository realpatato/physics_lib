#include <iostream>
#include <string>
#include <raylib.h>

#include "point.hpp"
#include "elipse.hpp"
#include "constants.hpp"
#include "simplex.hpp"

int main() {
    const int screen_width = constants::screen_width;
    const int screen_height = constants::screen_height;

    InitWindow(screen_width, screen_height, "basic window");

    //non-touching
    Elipse e1 = Elipse(Point(-250, -125), 20, 20);
    Elipse e2 = Elipse(Point(250, -125), 20, 20);

    Simplex s = e1.get_simplex(e2);

    std::cout << s.get_exists() << std::endl;

    //touching
    Elipse e3 = Elipse(Point(-10, 125), 20, 20);
    Elipse e4 = Elipse(Point(10, 125), 20, 20);

    Point sp1 = e3.get_simplex_point1(e4);
    Point sp2 = e3.get_simplex_point2(Point(0, 0) - sp1, e4);

    std::cout << sp1.get_x() << ", " << sp1.get_y() << std::endl;
    std::cout << sp2.get_x() << ", " << sp2.get_y() << std::endl;

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

        EndDrawing();
    }

    CloseWindow();
    return 0;
}