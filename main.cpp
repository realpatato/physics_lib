#include <iostream>
#include <string>
#include <array>
#include <raylib.h>

class Point {
    private:
        float x;
        float y;
    public:
        Point(float x, float y) : x(x), y(y) {}

        float get_x() {
            return x;
        }

        float get_y() {
            return y;
        }
};

class Elipse {
    private:
        Point center;
        float h_rad;
        float v_rad;
    public:
        //constructors
        Elipse(Point c, float h, float v) : center(c), h_rad(h), v_rad(v) {}
        //if given single radius (circle wider than default)
        Elipse(Point c, float r) : Elipse(c, r, r) {}
        //if given no radius (default circle)
        Elipse(Point c) : Elipse(c, 50, 50) {}

        void draw_self() {
            DrawEllipse((int) center.get_x(), (int) center.get_y(), h_rad, v_rad, RED);
        }
};

int main() {
    const int screen_width = 1000;
    const int screen_height = 500;

    InitWindow(screen_width, screen_height, "basic window");

    Point p = Point(0, 0);
    std::cout << p.get_x() << ", " << p.get_y() << std::endl; 

    Elipse e = Elipse(Point(500, 250), 50, 100);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(RAYWHITE);
            e.draw_self();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}