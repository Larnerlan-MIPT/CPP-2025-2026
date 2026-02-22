#include "raylib.h"
#include <cmath>

int main() {
    int w = 800, h = 600;
    InitWindow(w, h, "Task 8b");
    SetTargetFPS(60);
    float a = 400, b = 300, c = 0, d = 0, e = 0.2f, f = 20;
    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 m = GetMousePosition();
            float dx = m.x - a;
            float dy = m.y - b;
            float len = sqrt(dx*dx + dy*dy);
            if (len > 0.1f) {
                c += (dx / len) * e;
                d += (dy / len) * e;
            }
        }
        a += c;
        b += d;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(a, b, f, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}