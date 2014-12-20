#include "CRoom.h"

#include "Game/Inventory/CItem.h"

CRoom::CRoom(unsigned int w, unsigned int h)
: width(w), height(h)
{
    //empty
}

bool CRoom::insertItem(CItem* newItem, unsigned int slotIndex)
{
    if(slotIndex < (width * height))
    {
        if(itemSpace.getSize() < (width * height)) //still space to add stuff
        {
            if(itemSpace.getItem(slotIndex) == nullptr)
            {
                itemSpace.insertItem(newItem, slotIndex);

                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

unsigned int CRoom::get_Width()
{
    return width;
}

unsigned int CRoom::get_Height()
{
    return height;
}
