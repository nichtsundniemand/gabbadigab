#ifndef CROOM_H
    #define CROOM_H

#include <vector>

#include "Game/Inventory/CItemContainer.h"

class CRoom
{
    private:
        unsigned int width;
        unsigned int height;

    public:
        CItemContainer itemSpace;

        CRoom(unsigned int w, unsigned int h);

        bool insertItem(CItem* newItem, unsigned int slotIndex);

        unsigned int get_Width();
        unsigned int get_Height();
};

#endif
