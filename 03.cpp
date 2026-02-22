#include "raylib.h"

int main() {
    int w = 800;
    int h = 600;
    InitWindow(w, h, "Task 3");
    SetTargetFPS(60);
    float a = 400.0f;
    float b = 300.0f;
    float c = 100.0f;
    float d = 0.0f;
    float e = 0.05f;
    while (!WindowShouldClose()) {
        d = d + e;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectanglePro((Rectangle){a, b, c, c}, (Vector2){0, 0}, d * RAD2DEG, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}