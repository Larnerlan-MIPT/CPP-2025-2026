#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    int w = 800, h = 600;
    InitWindow(w, h, "Task 9");
    SetTargetFPS(60);
    srand(time(0));
    std::vector<float> a, b;
    std::vector<Color> c;
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 d = GetMousePosition();
            a.push_back(d.x);
            b.push_back(d.y);
            c.push_back(WHITE);
        }
        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 0; i < (int)c.size(); i++) {
                c[i] = (Color){ (unsigned char)GetRandomValue(0,255),
                                 (unsigned char)GetRandomValue(0,255),
                                 (unsigned char)GetRandomValue(0,255), 255 };
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < (int)a.size(); i++) {
            DrawCircle((int)a[i], (int)b[i], 10, c[i]);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}