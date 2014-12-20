#ifndef ROBJECTENTITY_H
    #define ROBJECTENTITY_H

#include "CRenderObject.h"
#include "Game/Entities/CGameEntity.h"

class RObjectEntity: public CRenderObject
{
    private:
        SDL_Texture* texture_Entity;

        CGameEntity* attachedEntity;

    public:
        RObjectEntity(SDL_Renderer* rend_Attaching, CGameEntity* attachingEntity);

        void OnRender();
};

#endif
