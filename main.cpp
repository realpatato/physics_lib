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
        std::array<int, 2> center;
};

int main() {
    const int screen_width = 1000;
    const int screen_height = 500;

    InitWindow(screen_width, screen_height, "basic window");

    int frame = 0;
    Point p = Point(0, 0);
    std::cout << p.get_x() << "," << p.get_y() << std::endl; 

    while (!WindowShouldClose()) {
        frame++;

        std::string frame_string = std::to_string(frame);
        const char* frame_char = frame_string.c_str();

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText(frame_char, 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}