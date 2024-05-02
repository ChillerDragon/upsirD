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

#endif

