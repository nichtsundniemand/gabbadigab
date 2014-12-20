#include "Game/CGame.h"

#include <SDL2/SDL_ttf.h>

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    CGame myGame;

    while(myGame.Running())
    {
        myGame.OnEvent();
        myGame.OnLoop();
        myGame.OnRender();
    }

    TTF_CloseFont(theFont);

    TTF_Quit();
    SDL_Quit();

    return 0;
}
