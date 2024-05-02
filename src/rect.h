#ifndef SRC_RECT_H
#define SRC_RECT_H

#include "global_state.h"
#include "raylib.h"
#include "user_input.h"

enum {
    BLOCK_IF,
    BLOCK_RIGHT,
    BLOCK_LEFT,
    BLOCK_UP,
    BLOCK_DOWN,
};

struct SRect
{
    int x;
    int y;
    int w;
    int h;
    Color color;
    int isDragged;
    struct SRect *child;
    struct SRect *parent;

    /* type     * 
     * can be one of the BLOCK_*
     * enums
*
     */
    int type;
    char text[128];
} typedef SRect;

void FillRectDefaults(SRect *rect);
void DrawRect(struct SRect *rect, SGlobalState *g);
void TickRect(SRect *rect, SUserInput *inp);
void DeleteRect(SRect *rect);

/* IsPosInRect
 *
 * returns 1 if the position is inside of the rect
 * returns 0 if the position is not inside of the rect
 *
 */
int IsPosInRect(Vector2 pos, SRect *rect);

#endif

