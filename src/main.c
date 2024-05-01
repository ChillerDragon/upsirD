#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "UwU");
    SetTargetFPS(-1);
    while (!WindowShouldClose())
    {
        // Update
        Vector2 mouse = GetMousePosition();
        TraceLog(LOG_INFO, "mouse %f %f", mouse.x, mouse.y);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

