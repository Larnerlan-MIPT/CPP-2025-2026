#include "raylib.h"
#include <string>

int main() {
    int w = 800;
    int h = 600;
    InitWindow(w, h, "Task 5");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        Vector2 m = GetMousePosition();
        std::string s = "X: " + std::to_string((int)m.x) + " Y: " + std::to_string((int)m.y);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(s.c_str(), 10, 10, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}