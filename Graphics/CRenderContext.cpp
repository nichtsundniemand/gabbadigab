#include "CRenderContext.h"

#include <iostream>

#include "SDL2/SDL_opengl.h"

CRenderContext::CRenderContext(std::string title, int x, int y, int w, int h)
{
    window = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_OPENGL);
    renderer = nullptr;
    glcontext = SDL_GL_CreateContext(window);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

SDL_Window* CRenderContext::get_Window()
{
    return window;
}

SDL_GLContext* CRenderContext::get_GLContext()
{
    return &glcontext;
}
