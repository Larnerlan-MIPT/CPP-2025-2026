#include "raylib.h"
#include <cmath>

int main() {
    int w = 800, h = 600;
    InitWindow(w, h, "Task 8a");
    SetTargetFPS(60);
    float a = 400, b = 300, c = 20, d = 3;
    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 m = GetMousePosition();
            float dx = m.x - a;
            float dy = m.y - b;
            float len = sqrt(dx*dx + dy*dy);
            if (len > 0.1f) {
                a += (dx / len) * d;
                b += (dy / len) * d;
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(a, b, c, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}