#include <raylib.h>
#include <vector>
#include <string>

class DropList
{
private:
    Rectangle mMainRect;
    std::vector<std::string> mItems;
    int mSelectedIndex;
    bool mExpanded;
public:
    DropList(Rectangle rect, const std::vector<std::string>& items)
        : mMainRect(rect), mItems(items), mSelectedIndex(0), mExpanded(false) {}

    void handleEvent()
    {
        Vector2 mouse = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mMainRect))
            {
                mExpanded = !mExpanded;
            }
            else if (mExpanded)
            {
                for (size_t i = 0; i < mItems.size(); i++)
                {
                    Rectangle itemRect = { mMainRect.x, mMainRect.y + (i+1)*mMainRect.height,
                                           mMainRect.width, mMainRect.height };
                    if (CheckCollisionPointRec(mouse, itemRect))
                    {
                        mSelectedIndex = i;
                        mExpanded = false;
                        break;
                    }
                }
                if (!CheckCollisionPointRec(mouse, {mMainRect.x, mMainRect.y, mMainRect.width, mMainRect.height*(mItems.size()+1)}))
                    mExpanded = false;
            }
        }
    }

    void draw()
    {
        DrawRectangleRec(mMainRect, LIGHTGRAY);
        DrawText(mItems[mSelectedIndex].c_str(), mMainRect.x+5, mMainRect.y+5, 20, BLACK);
        DrawRectangleLinesEx(mMainRect, 1, DARKGRAY);

        if (mExpanded)
        {
            for (size_t i = 0; i < mItems.size(); i++)
            {
                Rectangle itemRect = { mMainRect.x, mMainRect.y + (i+1)*mMainRect.height,
                                       mMainRect.width, mMainRect.height };
                DrawRectangleRec(itemRect, (i==mSelectedIndex ? SKYBLUE : LIGHTGRAY));
                DrawText(mItems[i].c_str(), itemRect.x+5, itemRect.y+5, 20, BLACK);
                DrawRectangleLinesEx(itemRect, 1, DARKGRAY);
            }
        }
    }

    int getSelectedIndex() const { return mSelectedIndex; }
};

int main()
{
    InitWindow(800, 600, "DropList Test");
    SetTargetFPS(60);

    DropList list({300, 200, 200, 40}, {"Krug", "Kvadrat", "Treugolnik"});

    while (!WindowShouldClose())
    {
        list.handleEvent();
        int sel = list.getSelectedIndex();

        BeginDrawing();
        ClearBackground(BLACK);
        list.draw();

        if (sel == 0)
            DrawCircle(600, 400, 50, WHITE);
        else if (sel == 1)
            DrawRectangle(550, 350, 100, 100, WHITE);
        else if (sel == 2)
        {
            Vector2 p1 = {600, 350}, p2 = {550, 450}, p3 = {650, 450};
            DrawTriangle(p1, p2, p3, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}