#include <iostream>
#include <string>
#include <raylib.h>

int main() {
    const int screen_width = 1000;
    const int screen_height = 500;

    InitWindow(screen_width, screen_height, "basic window");

    int frame = 0;

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