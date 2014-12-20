#include "CGame.h"

#include <SDL2/SDL_ttf.h>

CGame::CGame()
:   rendercontext_Main("Doubutsu no Mori", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, 1024, 768),

    Player1Renderer(nullptr, &Player1),

    theOnlyRoom(5, 4),
    theRoomsFace(nullptr, &theOnlyRoom),

    myInvDisp(nullptr, &myFirstInventory),

    cursor_Default(new CCursor),
    myNewCursorDisplay(nullptr, cursor_Default)
{
    TTF_Init();

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    myItemCatalog.OnLoad(nullptr, "");

    myInvDisp.OnLoad();
    myNewCursorDisplay.OnLoad("hand_open.png", "hand_closed.png");

    SDL_ShowCursor(0);

    int winwidth, winheight;
    SDL_GetWindowSize(rendercontext_Main.get_Window(), &winwidth, &winheight);

    myInvDisp.set_Pos((winwidth - 5 * 96)/2, winheight - 3 * 96);

    for(unsigned int i = 0; i < 13; i++)
    {
        CItem* newItem;

        if(i > 5)
            newItem = new CItemFurniture("chair");
        else if(i == 5)
            newItem = new CItem("letter");
        else
            newItem = new CItem("axe");

        myFirstInventory.inventoryItems.appendItem(newItem);
    }
}

bool CGame::Running()
{
    return running;
}

#include <iostream>
#warning: iostream

double frameTime_Max = 1000.0/30.0;

void CGame::OnLoop()
{
    Player1.OnLoop();

    frames++;
    currentFrameTime = SDL_GetTicks();
    if(currentFrameTime - lastFramePackTime > 1000)
    {
        std::cout << "FPS: " << frames / ((currentFrameTime - lastFramePackTime) / 1000.0) <<  std::endl;
        frames = 0;

        lastFramePackTime = currentFrameTime;
    }

    long mSecThisFrame = currentFrameTime - lastFrameTime;

    if(mSecThisFrame < frameTime_Max)
        SDL_Delay(frameTime_Max - mSecThisFrame);

    lastFrameTime = currentFrameTime;
}
