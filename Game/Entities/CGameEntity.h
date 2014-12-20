#ifndef CGAMEENTITY_H
    #define CGAMEENTITY_H

#include <SDL2/SDL.h>

//Onscreen Entities
class CGameEntity
{
    private:
        bool active; //determines, wether the Entity will respond to input, and will be updated

        long currentFrameTime;
        long lastFrameTime;

    protected:
        double pos_X;
        double pos_Y;

        long get_CurrentFrameTime();
        long get_LastFrameTime();

        virtual void EventHandler(SDL_Event* event) = 0;
        virtual void LoopHandler() = 0;

    public:
        CGameEntity();
        CGameEntity(bool activate);

        void Activate();
        void Deactivate();
        bool get_Active();

        double get_X();
        double get_Y();

        void OnEvent(SDL_Event* event);
        void OnLoop();
};

#endif
