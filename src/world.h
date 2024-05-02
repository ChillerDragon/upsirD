#ifndef SRC_WOLRD_H
#define SRC_WOLRD_H

#include "rect.h"
#include "user_input.h"

#define MAX_RECTS 1024

struct SWorld {
    SRect *rects[MAX_RECTS];
} typedef SWorld;

void InitWorld(SWorld *world);
void TickWorld(SWorld *world, SUserInput *inp);

#endif

