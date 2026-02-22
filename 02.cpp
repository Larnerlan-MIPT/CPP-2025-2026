#include "raylib.h"

int main() {
    int w = 800;
    int h = 600;
    InitWindow(w, h, "Task 2");
    SetTargetFPS(60);
    float a = 100.0f;
    float b = 3.0f;
    float c = 30.0f;
    while (!WindowShouldClose()) {
        a = a + b;
        if (a > w + c) {
            a = -c;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle((int)a, h/2, c, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}