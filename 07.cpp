#include "raylib.h"

int main() {
    int w = 800, h = 600;
    InitWindow(w, h, "Task 7");
    SetTargetFPS(60);
    float a = 400, b = 300, c = 20, d = 3;
    Color e = BLACK;
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            e = (Color){GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255};
        }
        if (IsKeyDown(KEY_RIGHT)) a += d;
        if (IsKeyDown(KEY_LEFT)) a -= d;
        if (IsKeyDown(KEY_DOWN)) b += d;
        if (IsKeyDown(KEY_UP)) b -= d;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(a, b, c, e);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}