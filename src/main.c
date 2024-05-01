#include "raylib.h"

struct SGlobalState
{
    Font font;
};

struct SRect
{
    int x;
    int y;
    int w;
    int h;
    Color color;
};


void Text(struct SGlobalState *g, const char *text, Vector2 position)
{
        DrawTextEx(g->font, "foo", (Vector2){ 20.0f, 100.0f }, (float)g->font.baseSize * 4, 2, LIME);
}

void DrawRect(struct SRect *rect)
{
        DrawRectangle(rect->x, rect->y, rect->w, rect->h, rect->color);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "UwU");
    SetTargetFPS(-1);

    struct SGlobalState g;
    // g.font = LoadFont("data/font.png");
    g.font = LoadFontEx("data/knowyour.ttf", 32, 0, 250);

    struct SRect rect = {
        0, 0, 10, 10, RED
    };

    while (!WindowShouldClose())
    {
        // Update
        Vector2 mouse = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            TraceLog(LOG_INFO, "mouse %f %f", mouse.x, mouse.y);
            rect.x = mouse.x;
            rect.y = mouse.y;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Text(&g, "foo", (Vector2){ 20.0f, 100.0f });

        DrawRect(&rect);

        EndDrawing();
    }

    UnloadFont(g.font);
    CloseWindow();
    return 0;
}

