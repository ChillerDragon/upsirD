#include "world.h"
#include "global_state.h"
#include "raylib.h"
#include "rect.h"
#include "user_input.h"
#include <stdlib.h>
#include <string.h>

#ifndef NULL
#define NULL 0
#endif

void InitWorld(SWorld *world)
{
    world->numRects = 0;
    for(int i = 0; i < MAX_RECTS; i++)
    {
        world->rects[i] = NULL;
    }
}

void TickWorld(SWorld *world, SUserInput *inp)
{
    for(int i = 0; i < MAX_RECTS; i++)
    {
        if(!world->rects[i])
            continue;
        TickRect(world->rects[i], inp);
    }
}

int AddRectToWorld(SWorld *world, SRect *rect)
{
    if(world->numRects >= MAX_RECTS)
        return 1;

    SRect *allocRect = malloc(sizeof(SRect));
    memcpy(allocRect, rect, sizeof(SRect));

    world->rects[world->numRects] = allocRect;
    world->numRects++;

    return 0;
}

void DrawWorld(SWorld *world, SGlobalState *g)
{
    for(int i = 0; i < MAX_RECTS; i++)
    {
        SRect *rect = world->rects[i];
        if(!rect)
             continue;

        DrawRect(rect, g);
    }
}

void RemoveRectFromWorld(SWorld *world, SRect *rect)
{
    for(int i = 0; i < MAX_RECTS; i++)
    {
        SRect *r = world->rects[i];
        if(!r)
             continue;
        if(r != rect)
            continue;

        DeleteRect(rect);
        free(r);
        r = NULL;
    }
}

void ShutdownWorld(SWorld *world)
{
    for(int i = 0; i < MAX_RECTS; i++)
    {
        if(!world->rects[i])
            continue;
        free(world->rects[i]);
    }
}

void OnLeftClick(SWorld *world, SUserInput *inp)
{
    TraceLog(LOG_INFO, "world got left mouse %f %f", inp->mousePos.x, inp->mousePos.y);
    for(int i = 0; i < MAX_RECTS; i++)
    {
        SRect *rect = world->rects[i];
        if(!rect)
            continue;

        TraceLog(LOG_INFO, "got rect at %d %d", rect->x, rect->y);
        if(IsPosInRect(inp->mousePos, rect))
        {
            TraceLog(LOG_INFO, " ** clicked rect at %d %d", rect->x, rect->y);
            rect->isDragged ^= 1;
            if(rect->isDragged)
            {
                if(rect->child)
                    rect->child->isDragged = 1;
            }

            for(int i = 0; i < MAX_RECTS; i++)
            {
                SRect *merge = world->rects[i];
                if(!merge)
                    continue;
                if(merge == rect)
                    continue;

                if(IsPosInRect(inp->mousePos, merge))
                {
                    merge->parent = rect;
                    rect->child = merge;

                    // can only merge with one other rect
                    break;
                }
            }

            // can only drag one rect at a time
            break;
        }
    }
}

