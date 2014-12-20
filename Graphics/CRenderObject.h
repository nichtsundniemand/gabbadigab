#ifndef CRENDEROBJECT_H
    #define CRENDEROBJECT_H

#include <SDL2/SDL.h>

class CRenderObject
{
    protected:
        SDL_Renderer* rend_Attached;

    public:
        CRenderObject(SDL_Renderer* rend_Attaching);

        virtual void OnRender() = 0;
};

#endif
