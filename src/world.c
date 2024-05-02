#include "world.h"
#include "raylib.h"
#include "rect.h"
#include "user_input.h"

#ifndef NULL
#define NULL 0
#endif

void InitWorld(SWorld *world)
{
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

            // can only drag one rect at a time
            break;
        }
    }
}

