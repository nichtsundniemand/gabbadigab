#include "CGame.h"

void CGame::OnRender()
{
    SDL_RenderClear(rendercontext_Main.get_Renderer());

    theRoomsFace.OnRender();
    Player1Renderer.OnRender();
    myInvDisp.OnRender(&myItemCatalog);
    myNewCursorDisplay.OnRender(myItemCatalog);

    SDL_RenderPresent(rendercontext_Main.get_Renderer());
}
