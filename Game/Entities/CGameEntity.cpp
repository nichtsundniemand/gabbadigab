#include "CGameEntity.h"

CGameEntity::CGameEntity()
: active(true), pos_X(0), pos_Y(0)
{
    //empty
}

CGameEntity::CGameEntity(bool activate)
: active(activate), pos_X(0), pos_Y(0)
{
    //empty
}


void CGameEntity::Activate()
{
    active = true;
}

void CGameEntity::Deactivate()
{
    active = false;
}

bool CGameEntity::get_Active()
{
    return active;
}


double CGameEntity::get_X()
{
    return pos_X;
}

double CGameEntity::get_Y()
{
    return pos_Y;
}


long CGameEntity::get_CurrentFrameTime()
{
    return currentFrameTime;
}

long CGameEntity::get_LastFrameTime()
{
    return lastFrameTime;
}


void CGameEntity::OnEvent(SDL_Event* event)
{
    if(active)
        EventHandler(event);
}

void CGameEntity::OnLoop()
{
    currentFrameTime = SDL_GetTicks();
    if(active)
        LoopHandler();

    lastFrameTime = currentFrameTime;
}
