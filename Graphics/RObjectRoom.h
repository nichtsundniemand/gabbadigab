#ifndef ROBJECTROOM_H
    #define ROBJECTROOM_H

#include "CRenderObject.h"

#include "Game/Room/CRoom.h"

class RObjectRoom: public CRenderObject
{
    private:
        CRoom* attachedRoom;

        unsigned int tileSize;

        unsigned int roomWidth;
        unsigned int roomHeight;

    public:
        RObjectRoom(SDL_Renderer* rend_Attaching, CRoom* attachingRoom);

        void OnRender();
};

#endif
