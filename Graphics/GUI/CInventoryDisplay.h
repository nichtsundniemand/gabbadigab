#ifndef CINVENTORYDISPLAY_H
    #define CINVENTORYDISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class CItemCatalog;
#include "Game/Inventory/CInventory.h"

static TTF_Font* theFont;

bool isInRect(SDL_Rect* rect_Check, int pos_x, int pos_y);

class CInventoryDisplay
{
    private:
        SDL_Renderer* rend_Attached;
        SDL_Texture* texture_Background; //will be composed on init
        SDL_Texture* texture_Item;

        int posX, posY;
        unsigned char boxrim;
        unsigned char boxsize;
        SDL_Rect rect_Background;
        SDL_Rect boxes[14];

        bool hidden;

        CInventory* attachedInventory;

public:
#warning: this shouldnt be public, i guess?
        unsigned int coordsToIndex(unsigned int pos_x, unsigned int pos_y);
        SDL_Rect indexToCords(unsigned int index);

    public:
        CInventoryDisplay(SDL_Renderer* rend_Attaching, CInventory* attachingInventory);
        ~CInventoryDisplay();

        void set_Pos(int pos_x, int pos_y);
        void set_Hide(bool hide);

        bool get_Hide();

        bool OnLoad();
        void OnRender(CItemCatalog* itemDefs);
};

#endif
