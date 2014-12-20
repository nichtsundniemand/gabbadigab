#include "CCursorDisplay.h"

#include <iostream>

#include <SDL2/SDL_image.h>

#include "Game/Inventory/CItemCatalog.h"

CCursorDisplay::CCursorDisplay(SDL_Renderer* rend_Attaching, CCursor* attachingCursor)
: rend_Attached(rend_Attaching), texture_PointerNormal(nullptr), texture_PointerGrab(nullptr), attachedCursor(attachingCursor)
{
    //empty
}

CCursorDisplay::~CCursorDisplay()
{
    SDL_DestroyTexture(texture_PointerNormal);
    SDL_DestroyTexture(texture_PointerGrab);
}

CCursor* CCursorDisplay::attachCursor(CCursor* attachingCursor)
{
    if(attachingCursor == nullptr)
        return nullptr;
    else
    {
        CCursor* oldCursor = attachedCursor;

        attachedCursor = attachingCursor;

        return oldCursor;
    }
}

bool CCursorDisplay::OnLoad(std::string filename_pointer_normal, std::string filename_pointer_grab)
{
    bool errorstate = true;

    SDL_Surface *surf_1, *surf_2;

    if((texture_PointerNormal = SDL_CreateTextureFromSurface(rend_Attached, surf_1 = IMG_Load(filename_pointer_normal.c_str()))) == nullptr)
    {
        std::cout << "Error loading image file: " << filename_pointer_normal << "\n\t" << SDL_GetError() << std::endl;
        errorstate = false;
    }

    if((texture_PointerGrab = SDL_CreateTextureFromSurface(rend_Attached, surf_2 = IMG_Load(filename_pointer_grab.c_str()))) == nullptr)
    {
        std::cout << "Error loading image file: " << filename_pointer_grab << "\n\t" << SDL_GetError() << std::endl;
        errorstate = false;
    }

    SDL_FreeSurface(surf_1);
    SDL_FreeSurface(surf_2);

    return errorstate;
}

void CCursorDisplay::OnRender(CItemCatalog& theItemCatalog)
{
    SDL_Rect rect_Dest = {attachedCursor->get_X(), attachedCursor->get_Y(), 32, 32};
    #warning FIXME (therufuser#1#): Make w and h variable

    switch(attachedCursor->get_Type())
    {
        case CURSORTYPE_DEFAULT:
        {
            if(attachedCursor->get_Left())
            {
                if(texture_PointerGrab != nullptr)
                    SDL_RenderCopy(rend_Attached, texture_PointerGrab, nullptr, &rect_Dest);
            }
            else
            {
                if(texture_PointerNormal != nullptr)
                    SDL_RenderCopy(rend_Attached, texture_PointerNormal, nullptr, &rect_Dest);
            }

            break;
        }

        case CURSORTYPE_ITEM:
        {
            rect_Dest.w = rect_Dest.h = 64;

            rect_Dest.x -= rect_Dest.w / 2; //center the Icon on the cursor
            rect_Dest.y -= rect_Dest.h / 2; //center the Icon on the cursor

            if(attachedCursor->get_Left())
            {
                SDL_Texture* texture_ItemCursor = theItemCatalog.get_ItemIcon(((CItemCursor*)attachedCursor)->get_Item()->getItemID());

                if(texture_ItemCursor != nullptr)
                    SDL_RenderCopy(rend_Attached, texture_ItemCursor, nullptr, &rect_Dest);
            }

            break;
        }
    }
}
