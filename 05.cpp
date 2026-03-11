#include <raylib.h>
#include <vector>

class Toggle
{
private:
    Rectangle mRect;
    float mThumbPos;
    bool mState;
    bool mPressed;
public:
    Toggle(Rectangle rect) : mRect(rect), mThumbPos(0.0f), mState(false), mPressed(false) {}

    void handleEvent()
    {
        Vector2 mouse = GetMousePosition();
        if (CheckCollisionPointRec(mouse, mRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            mState = !mState;
            mThumbPos = mState ? 1.0f : 0.0f;
        }
    }

    void draw()
    {
        Color bgColor = mState ? GREEN : DARKGRAY;
        DrawRectangleRec(mRect, bgColor);
        float thumbX = mRect.x + mThumbPos * (mRect.width - mRect.height);
        DrawCircle(thumbX + mRect.height/2, mRect.y + mRect.height/2, mRect.height/2 - 2, WHITE);
    }
};

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "10 Toggles");
    SetTargetFPS(60);

    std::vector<Toggle> toggles;
    for (int i = 0; i < 10; i++)
    {
        float x = 100 + (i % 5) * 120;
        float y = 100 + (i / 5) * 80;
        toggles.emplace_back(Rectangle{x, y, 100, 40});
    }

    while (!WindowShouldClose())
    {
        for (auto& t : toggles) t.handleEvent();

        BeginDrawing();
        ClearBackground(BLACK);
        for (auto& t : toggles) t.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}