#include "raylib.h"

struct SGlobalState
{
    Font font;
};


void Text(struct SGlobalState *g, const char *text, Vector2 position)
{
        DrawTextEx(g->font, "foo", (Vector2){ 20.0f, 100.0f }, (float)g->font.baseSize * 4, 2, LIME);
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

    while (!WindowShouldClose())
    {
        // Update
        Vector2 mouse = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            TraceLog(LOG_INFO, "mouse %f %f", mouse.x, mouse.y);
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Text(&g, "foo", (Vector2){ 20.0f, 100.0f });
        EndDrawing();
    }

    UnloadFont(g.font);
    CloseWindow();
    return 0;
}

