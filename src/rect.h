#ifndef SRC_RECT_H
#define SRC_RECT_H

#include "raylib.h"
#include "user_input.h"

struct SRect
{
    int x;
    int y;
    int w;
    int h;
    Color color;
    int isDragged;
} typedef SRect;

void FillRectDefaults(SRect *rect);
void TickRect(SRect *rect, SUserInput *inp);

/* IsPosInRect
 *
 * returns 1 if the position is inside of the rect
 * returns 0 if the position is not inside of the rect
 *
 */
int IsPosInRect(Vector2 pos, SRect *rect);

#endif

