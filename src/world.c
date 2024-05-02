#include "world.h"
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

