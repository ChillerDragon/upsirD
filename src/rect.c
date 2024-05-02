#include "global_state.h"
#include "raylib.h"
#include "user_input.h"
#include <string.h>

#include "rect.h"

void FillRectDefaults(SRect *rect)
{
    rect->x = 0;
    rect->y = 0;
    rect->w = 100;
    rect->h = 100;
    rect->color = GREEN;
    rect->isDragged = false;
    rect->type = BLOCK_IF;
    rect->parent = NULL;
    rect->child = NULL;
    strncpy(rect->text, "if", sizeof(rect->text));
}

void DeleteRect(SRect *rect)
{
        TraceLog(LOG_INFO, "TODO: cleanup rect stuff");
}

void DrawRect(struct SRect *rect, SGlobalState *g)
{
        DrawRectangle(rect->x, rect->y, rect->w, rect->h, rect->color);
        DrawTextEx(
            g->font,
            rect->text,
            (Vector2){ rect->x, rect->y },
            (float)g->font.baseSize,
            2,
            BLACK);
}

void TickRect(SRect *rect, SUserInput *inp)
{
    if(rect->isDragged)
    {
        rect->x = inp->mousePos.x;
        rect->y = inp->mousePos.y;
    }
}

int IsPosInRect(Vector2 pos, SRect *rect)
{
    int px = pos.x;
    int py = pos.y;
    int rx = rect->x;
    int ry = rect->y;
    int rw = rect->w;
    int rh = rect->h;

    if(px < rx)
    {
        TraceLog(LOG_INFO, "pos on the left side of the rect %d < %d", px, rx);
        return 0;
    }
    if(py < ry)
    {
        TraceLog(LOG_INFO, "pos above the rect %d < %d", py, ry);
        return 0;
    }
    if(px > rx + rw)
    {
        TraceLog(LOG_INFO, "pos on the right of the rect %d > %d", px, rx + rw);
        return 0;
    }
    if(py > ry + rh)
    {
        TraceLog(LOG_INFO, "pos on the bottom of the rect %d > %d", py, ry + rh);
        return 0;
    }
    TraceLog(LOG_INFO, "pos inside of the rect");
    return 1;
}

