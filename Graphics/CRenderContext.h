#ifndef CRENDERCONTEXT_H
    #define CRENDERCONTEXT_H

#include <string>

#include <SDL2/SDL.h>

class CRenderContext
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_GLContext glcontext;

    public:
        CRenderContext(std::string title, int x, int y, int w, int h);

        SDL_Window* get_Window();
        SDL_GLContext* get_GLContext();
};

#endif
