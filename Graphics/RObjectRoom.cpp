#include "RObjectRoom.h"

#include "Game/Inventory/CItem.h"

RObjectRoom::RObjectRoom(SDL_Renderer* rend_Attaching, CRoom* attachingRoom)
: CRenderObject(rend_Attaching), attachedRoom(attachingRoom), tileSize(96), roomWidth(attachedRoom->get_Width()), roomHeight(attachedRoom->get_Height())
{
    //empty
}

void RObjectRoom::OnRender()
{
    /*unsigned int xOffset = (surf_Dest->w - (tileSize * roomWidth)) / 2;
    unsigned int yOffset = (surf_Dest->h - (tileSize * roomHeight)) / 2;

    SDL_FillRect(surf_Dest, NULL, SDL_MapRGB(surf_Dest->format, 192, 0, 48));

    CItem* theItem = nullptr;
    for(unsigned int row = 0; row < roomHeight; row++)
    {
        for(unsigned int column = 0; column < roomWidth; column++)
        {
            theItem = attachedRoom->itemSpace.getItem(row * roomWidth + column);

            if(theItem != nullptr)
            {
                SDL_Rect rect_Fill = {xOffset + column * tileSize, yOffset + row * tileSize, tileSize, tileSize};

                SDL_FillRect(surf_Dest, &rect_Fill, SDL_MapRGB(surf_Dest->format, 0, 48, 32 * (theItem->getGroupID() + 1)));
            }
        }
    }*/
    #warning: Commented out
}
