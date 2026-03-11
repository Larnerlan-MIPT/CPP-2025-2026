#include "raylib.h"
#include <algorithm>

class Slider
{
protected:
    Rectangle mTrackRect, mThumbRect;
    bool mIsPressed{false};
public:
    Slider(Vector2 center, Vector2 trackSize, Vector2 thumbSize)
    {
        mTrackRect = { center.x - trackSize.x/2, center.y - trackSize.y/2, trackSize.x, trackSize.y };
        mThumbRect = { center.x - thumbSize.x/2, center.y - thumbSize.y/2, thumbSize.x, thumbSize.y };
    }
    void draw()
    {
        DrawRectangleRec(mTrackRect, {200,200,220,255});
        DrawRectangleRec(mThumbRect, {150,150,240,255});
    }
    void setRestrictedThumbPosition(Vector2 pos)
    {
        float minX = mTrackRect.x;
        float maxX = mTrackRect.x + mTrackRect.width;
        pos.x = std::clamp(pos.x, minX, maxX);
        mThumbRect.x = pos.x - mThumbRect.width/2;
    }
    bool handleEvent()
    {
        Vector2 mouse = GetMousePosition();
        bool res = false;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mThumbRect) || CheckCollisionPointRec(mouse, mTrackRect))
            {
                mIsPressed = true;
                setRestrictedThumbPosition(mouse);
                res = true;
            }
        }
        if (mIsPressed && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0))
            setRestrictedThumbPosition(mouse);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) mIsPressed = false;
        return res;
    }
    float getValue() const
    {
        float start = mTrackRect.x;
        float end = mTrackRect.x + mTrackRect.width;
        float pos = mThumbRect.x + mThumbRect.width/2;
        return 100.0f * (pos - start) / (end - start);
    }
};

int main()
{
    InitWindow(800, 600, "RGB Sliders");
    SetTargetFPS(60);

    Slider redSlider({200, 500}, {300, 20}, {20, 50});
    Slider greenSlider({400, 500}, {300, 20}, {20, 50});
    Slider blueSlider({600, 500}, {300, 20}, {20, 50});

    float r=0, g=0, b=0;

    while (!WindowShouldClose())
    {
        redSlider.handleEvent();
        greenSlider.handleEvent();
        blueSlider.handleEvent();

        r = redSlider.getValue() * 2.55f;
        g = greenSlider.getValue() * 2.55f;
        b = blueSlider.getValue() * 2.55f;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(400, 200, 80, Color{(unsigned char)r, (unsigned char)g, (unsigned char)b, 255});
        redSlider.draw();
        greenSlider.draw();
        blueSlider.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}