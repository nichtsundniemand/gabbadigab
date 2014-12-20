#ifndef CGAME_H
    #define CGAME_H

#include <SDL2/SDL.h>

#include "Entities/GEntityPlayer.h"

#include "Graphics/CRenderContext.h"
#include "Graphics/RObjectRoom.h"
#include "Graphics/RObjectEntity.h"
#include "Graphics/GUI/CInventoryDisplay.h"
#include "Graphics/GUI/CCursorDisplay.h"

#include "Inventory/CItemCatalog.h"
#include "Inventory/CInventory.h"
#include "Room/CRoom.h"

class CGame
{
    private:
        bool running = true;

        CRenderContext rendercontext_Main;

        GEntityPlayer Player1;
        RObjectEntity Player1Renderer;

        CRoom theOnlyRoom;
        RObjectRoom theRoomsFace;

        CItemCatalog myItemCatalog;

        CInventory myFirstInventory;
        CInventoryDisplay myInvDisp;

        CItemStack myNewStack;

        CCursor* cursor_Default;
        CCursorDisplay myNewCursorDisplay;

        SDL_Event theEvent;

        long currentFrameTime, lastFrameTime, lastFramePackTime, frames;

    public:
        CGame();

        bool Running();

        void OnEvent();
        void OnLoop();
        void OnRender();
};

#endif
