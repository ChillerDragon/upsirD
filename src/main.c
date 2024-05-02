#include "raylib.h"

#include "rect.h"
#include "global_state.h"
#include "world.h"
#include "user_input.h"

void Text(SGlobalState *g, const char *text, Vector2 position)
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

    SWorld world;
    InitWorld(&world);

    SRect rect;
    FillRectDefaults(&rect);
    world.rects[0] = &rect;

    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_Q))
            break;

        // Update
        SUserInput inp;
        inp.mousePos = GetMousePosition();
        inp.leftClicked = 0;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            inp.leftClicked = 1;
            OnLeftClick(&world, &inp);
        }
        TickWorld(&world, &inp);

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

