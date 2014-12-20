#include "RObjectEntity.h"

#include <iostream>
RObjectEntity::RObjectEntity(SDL_Renderer* rend_Attaching, CGameEntity* attachingEntity)
: CRenderObject(rend_Attaching), attachedEntity(attachingEntity)
{
    SDL_Surface* surf_Temp = SDL_CreateRGBSurface(0, 64, 96, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_FillRect(surf_Temp, NULL, SDL_MapRGB(surf_Temp->format, 192, 192, 192));
    if(surf_Temp == nullptr)
        std::cout << "SCREAM!!!" << std::endl;

    texture_Entity = SDL_CreateTextureFromSurface(rend_Attached, surf_Temp);
    if(texture_Entity == nullptr)
        std::cout << "SCREAM!!!" << SDL_GetError() << std::endl;

    SDL_FreeSurface(surf_Temp);
}

void RObjectEntity::OnRender()
{
    if(attachedEntity->get_Active())
    {
        SDL_Rect rect_Dest = {attachedEntity->get_X(), attachedEntity->get_Y(), 64, 96};

        SDL_RenderCopy(rend_Attached, texture_Entity, NULL, &rect_Dest);
    }
}
