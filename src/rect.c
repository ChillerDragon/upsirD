#include "raylib.h"
#include "user_input.h"

#include "rect.h"

void FillRectDefaults(SRect *rect)
{
    rect->x = 0;
    rect->y = 0;
    rect->w = 100;
    rect->h = 100;
    rect->color = GREEN;
    rect->isDragged = false;
}

void TickRect(SRect *rect, SUserInput *inp)
{
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            TraceLog(LOG_INFO, "mouse %f %f", inp->mousePos.x, inp->mousePos.y);
            rect->x = inp->mousePos.x;
            rect->y = inp->mousePos.y;
        }
}

