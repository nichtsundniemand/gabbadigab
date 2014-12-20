#ifndef CCURSORDISPLAY_H
    #define CCURSORDISPLAY_H

#include <string>

#include <SDL2/SDL.h>

#include "Game/Input/CCursor.h"
class CItemCatalog;

class CCursorDisplay
{
    private:
        SDL_Renderer* rend_Attached;

        SDL_Texture *texture_PointerNormal, *texture_PointerGrab;

        CCursor* attachedCursor;

    public:
        CCursorDisplay(SDL_Renderer* rend_Attaching, CCursor* attachingCursor);
        ~CCursorDisplay();

        CCursor* attachCursor(CCursor* attachingCursor);

        bool OnLoad(std::string filename_pointer_normal, std::string filename_pointer_grab);
        void OnRender(CItemCatalog& theItemCatalog);
        #warning: do we want this here?
};

#endif
