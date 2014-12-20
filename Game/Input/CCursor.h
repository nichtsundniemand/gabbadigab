#ifndef CCURSOR_H
    #define CCURSOR_H

#include <SDL2/SDL.h>

#include "Game/Inventory/CItem.h"

enum CursorType
{
    CURSORTYPE_DEFAULT,
    CURSORTYPE_ITEM
};

class CCursor
{
    private:
        CursorType thisCursor;

    protected:
        int posX, posY;

        bool leftClicked, rightClicked, middleClicked;

        CCursor(CursorType newType);
        CCursor(CCursor& referenceCursor, CursorType newType);

    public:
        CCursor();
        CCursor(CCursor& referenceCursor);

        int get_X();
        int get_Y();

        bool get_Left();
        bool get_Right();
        bool get_Middle();

        CursorType get_Type();

        void OnEvent(SDL_Event* event);
};

class CItemCursor: public CCursor
{
    private:
        CItem* attachedItem;

        unsigned int oldSlot;

    public:
        CItemCursor(CItem* attachingItem, unsigned int receiveSlot);
        CItemCursor(CCursor& referenceCursor, CItem* attachingItem, unsigned int receiveSlot);

        CItem* get_Item();
        unsigned int get_Slot();
};

#endif
