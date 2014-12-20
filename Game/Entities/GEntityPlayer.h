#ifndef GENTITYPLAYER_H
    #define GENTITYPLAYER_H

#include "CGameEntity.h"

enum direction
{
    SOUTH, SOUTHWEST, WEST, NORTHWEST, NORTH, NORTHEAST, EAST, SOUTHEAST
};

enum movementState
{
    NEGATIVE = -1, STILL, POSITIVE
};

class GEntityPlayer: public CGameEntity
{
    private:
        movementState horiztl;
        movementState verticl;

        direction facing;

        float speed_X;
        float speed_Y;

        float acceleration;

        void EventHandler(SDL_Event* event);
        void LoopHandler();

    public:
        GEntityPlayer();
};

#endif
