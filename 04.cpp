#include "raylib.h"
#include <cmath>

int main() {
    int w = 800;
    int h = 600;
    InitWindow(w, h, "Task 4");
    SetTargetFPS(60);
    float a = 0.0f;
    float b = 0.02f;
    float c = 150.0f;
    float d = 30.0f;
    int cx = w/2;
    int cy = h/2;
    while (!WindowShouldClose()) {
        a = a + b;
        float x = cx + c * cos(a);
        float y = cy + c * sin(a);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle((int)x, (int)y, d, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}