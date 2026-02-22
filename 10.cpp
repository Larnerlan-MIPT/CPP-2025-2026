#include "raylib.h"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main() {
    int w = 800, h = 600;
    InitWindow(w, h, "Task 10");
    SetTargetFPS(60);
    float dt = 1.0f/60.0f;
    float minR = 5.0f;
    std::vector<float> x, y, vx, vy, m, q;
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        x.push_back(rand() % (w-100) + 50);
        y.push_back(rand() % (h-100) + 50);
        vx.push_back(0);
        vy.push_back(0);
        m.push_back(rand()%10 + 1);
        q.push_back(rand()%11 - 5);
    }
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 p = GetMousePosition();
            x.push_back(p.x);
            y.push_back(p.y);
            vx.push_back(0);
            vy.push_back(0);
            m.push_back(0.5f);
            q.push_back(-1.0f);
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            Vector2 p = GetMousePosition();
            x.push_back(p.x);
            y.push_back(p.y);
            vx.push_back(0);
            vy.push_back(0);
            m.push_back(10.0f);
            q.push_back(1.0f);
        }
        int n = x.size();
        std::vector<float> fx(n, 0), fy(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                float dx = x[i] - x[j];
                float dy = y[i] - y[j];
                float r = sqrt(dx*dx + dy*dy);
                if (r < minR) continue;
                float f = (q[i] * q[j]) / (r * r);
                float fxi = f * dx;
                float fyi = f * dy;
                fx[i] += fxi;
                fy[i] += fyi;
                fx[j] -= fxi;
                fy[j] -= fyi;
            }
        }
        for (int i = 0; i < n; i++) {
            if (m[i] > 0) {
                vx[i] += (fx[i] / m[i]) * dt;
                vy[i] += (fy[i] / m[i]) * dt;
            }
            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
            if (x[i] < 0) { x[i] = -x[i]; vx[i] = -vx[i]; }
            if (x[i] > w) { x[i] = 2*w - x[i]; vx[i] = -vx[i]; }
            if (y[i] < 0) { y[i] = -y[i]; vy[i] = -vy[i]; }
            if (y[i] > h) { y[i] = 2*h - y[i]; vy[i] = -vy[i]; }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < n; i++) {
            Color col = q[i] > 0 ? RED : (q[i] < 0 ? BLUE : GRAY);
            DrawCircle((int)x[i], (int)y[i], 5, col);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}