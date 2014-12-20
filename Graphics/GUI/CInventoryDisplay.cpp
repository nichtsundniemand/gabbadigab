#include "CInventoryDisplay.h"

#include <iostream>

#include "Game/Inventory/CItem.h"
#include "Game/Inventory/CItemCatalog.h"

bool isInRect(SDL_Rect* rect_Check, int pos_x, int pos_y)
{
    int x1 = rect_Check->x;
    int x2 = x1 + rect_Check->w;
    int y1 = rect_Check->y;
    int y2 = y1 + rect_Check->h;

    if((pos_x >= x1) && (pos_x <= x2))
    {
        if(pos_y >= y1 && pos_y <=y2)
            return true;
        else
            return false;
    }
    else
        return false;
}

unsigned int CInventoryDisplay::coordsToIndex(unsigned int pos_x, unsigned int pos_y)
{
    if(isInRect(&rect_Background, pos_x, pos_y))
    {
        for(unsigned int i = 0; i < 14; i++)
        {
            SDL_Rect rect_Box = boxes[i];
            rect_Box.x += posX + boxrim;
            rect_Box.y += posY + boxrim;
            rect_Box.w -= 2 * boxrim;
            rect_Box.h -= 2 * boxrim;

            if(isInRect(&rect_Box, pos_x, pos_y))
                return i;
        }
    }

    return -1;
}

SDL_Rect CInventoryDisplay::indexToCords(unsigned int index)
{
    if(index < 14)
        return boxes[index];
    else
        return {0, 0, 0, 0};
}

CInventoryDisplay::CInventoryDisplay(SDL_Renderer* rend_Attaching, CInventory* attachingInventory)
: rend_Attached(rend_Attaching), boxrim(4), boxsize(96), hidden(true), attachedInventory(attachingInventory)
{
    set_Pos(0, 0);

    for(unsigned int i = 0; i < 5; i++)
        boxes[i] = {(short)(i * boxsize), 0, boxsize, boxsize};
    for(unsigned int i = 0; i < 4; i++)
        boxes[i + 5] = {(short)(i * boxsize + 0.5 * boxsize), boxsize, boxsize, boxsize};
    for(unsigned int i = 0; i < 5; i++)
        boxes[i + 9] = {(short)(i * boxsize), (short)(2 * boxsize), boxsize, boxsize};

    // TODO (therufuser#1#): Who actually wants this shit? Do some nice Texture loading.. although a fallback is always nice to have..
    SDL_Surface* surf_BG_Temp = SDL_CreateRGBSurface(0, rect_Background.w, rect_Background.h, 32, 0xFF << (16 * 2), 0xFF << 16, 0xFF, 0xFF << (16 * 3));

    if(surf_BG_Temp != nullptr)
    {
        SDL_FillRect(surf_BG_Temp, NULL, SDL_MapRGB(surf_BG_Temp->format, 192, 128, 0));

        for(unsigned int i = 0; i < 14; i++)
        {
            unsigned char fillrim = boxrim / 2;

            SDL_Rect rect_Box = {(short)(boxes[i].x + posX + fillrim), (short)(boxes[i].y + posY + fillrim), (unsigned short)(boxsize - 2 * fillrim), (unsigned short)(boxsize - 2 * fillrim)};

            SDL_FillRect(surf_BG_Temp, &rect_Box, SDL_MapRGB(surf_BG_Temp->format, 96, 64, 0));
        }

        texture_Background = SDL_CreateTextureFromSurface(rend_Attached, surf_BG_Temp);
        if(texture_Background == nullptr)
            std::cout << "CInventoryDisplay: Background texture creation failed!\n\t" << SDL_GetError() << std::endl;

        SDL_FreeSurface(surf_BG_Temp);
    }
    else
    {
        std::cout << "CInventoryDisplay: Background texture creation failed!\n\t" << SDL_GetError() << std::endl;
        texture_Background = nullptr;
    }
}

CInventoryDisplay::~CInventoryDisplay()
{
    theFont = nullptr;
}

void CInventoryDisplay::set_Pos(int pos_x, int pos_y)
{
    posX = pos_x;
    posY = pos_y;

    rect_Background = {(short)posX, (short)posY, (unsigned short)(5 * boxsize), (unsigned short)(3 * boxsize)};
}

void CInventoryDisplay::set_Hide(bool hide)
{
    hidden = hide;
}

bool CInventoryDisplay::get_Hide()
{
    return hidden;
}

bool CInventoryDisplay::OnLoad()
{
    theFont = TTF_OpenFont("VeraMono.ttf", 18);
    if(theFont == nullptr)
    {
        std::cout << "Font loading Fail!\n\t" << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void CInventoryDisplay::OnRender(CItemCatalog* itemDefs)
{
    if(!hidden)
    {
        SDL_RenderCopy(rend_Attached, texture_Background, NULL, &rect_Background);

        for(unsigned int i = 0; i < 14; i++)
        {
            SDL_Rect rect_Box = {(short)(boxes[i].x + posX + boxrim), (short)(boxes[i].y + posY + boxrim), (unsigned short)(boxsize - 2 * boxrim), (unsigned short)(boxsize - 2 * boxrim)};

            CItem* theItem = attachedInventory->inventoryItems.getItem(i);

            if(theItem != nullptr)
            {
                SDL_Texture* texture_Temp = itemDefs->get_ItemIcon(theItem->getItemID());

                if(texture_Temp != nullptr)
                    SDL_RenderCopy(rend_Attached, texture_Temp, NULL, &rect_Box);
            }
        }
    }
}
