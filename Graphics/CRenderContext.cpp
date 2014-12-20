#include "CRenderContext.h"

CRenderContext::CRenderContext(std::string title, int x, int y, int w, int h)
{
    window = SDL_CreateWindow(title.c_str(), x, y, w, h, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

SDL_Window* CRenderContext::get_Window()
{
    return window;
}

SDL_Renderer* CRenderContext::get_Renderer()
{
    return renderer;
}
