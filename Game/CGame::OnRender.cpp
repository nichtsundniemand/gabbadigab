#include "CGame.h"

#include "SDL2/SDL_opengl.h"
#include "GL/glu.h"

void CGame::OnRender()
{
    int w = 1024, h = 768;
    float x = Player1.get_X(), y = Player1.get_Y();

    glViewport(0, 0, h, w);

    //3D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(45, (float) w / h, 0.1, 5000.0);
    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);



    glBegin(GL_QUADS);


    glColor3f(1.0,0.0,0.0);
    glVertex2f(x + 45.0, y+45.0);

    glColor3f(0.0,1.0,0.0);
    glVertex2f(x-45.0, y+45.0);

    glColor3f(0.0,0.0,1.0);
    glVertex2f(x-45.0, y-45.0);

    glVertex2f(x - 45.0, y + 45.0);


    glEnd();

    //SDL_RenderPresent(rendercontext_Main.get_Renderer());
    SDL_GL_SwapWindow(rendercontext_Main.get_Window());


    //ORTHO
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0f, w, h, 0.0f, 0.01, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.375, 0.375, 0.0);
    glDisable(GL_DEPTH_TEST);

    //theRoomsFace.OnRender();
    //Player1Renderer.OnRender();
    //myInvDisp.OnRender(&myItemCatalog);
    //myNewCursorDisplay.OnRender(myItemCatalog);
}
