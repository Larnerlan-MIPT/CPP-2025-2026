#include "raylib.h"

int main() {
    int w = 800, h = 600;
    InitWindow(w, h, "Task 6");
    SetTargetFPS(60);
    float a = 200, b = 200, c = 150, d = 100;
    while (!WindowShouldClose()) {
        Vector2 m = GetMousePosition();
        Color col;
        if (CheckCollisionPointRec(m, (Rectangle){a, b, c, d}))
            col = RED;
        else
            col = GREEN;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(a, b, c, d, col);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}