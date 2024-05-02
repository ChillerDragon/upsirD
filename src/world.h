#ifndef SRC_WOLRD_H
#define SRC_WOLRD_H

#include "rect.h"
#include "user_input.h"

#define MAX_RECTS 1024

struct SWorld {
    int numRects;
    SRect *rects[MAX_RECTS];
} typedef SWorld;

void InitWorld(SWorld *world);
void TickWorld(SWorld *world, SUserInput *inp);

/* AddRectToWorld
 *
 *
 *
 * returns 0 on failure (for example if the world is full)
 * returns 1 on success
 */
int AddRectToWorld(SWorld *world, SRect *rect);
void OnLeftClick(SWorld *world, SUserInput *inp);
void DrawWorld(SWorld *world);
void ShutdownWorld(SWorld *world);

#endif

