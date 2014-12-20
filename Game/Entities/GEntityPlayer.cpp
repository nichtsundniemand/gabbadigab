#include "GEntityPlayer.h"

GEntityPlayer::GEntityPlayer()
: horiztl(STILL), verticl(STILL), speed_X(0), speed_Y(0), acceleration(2000)
{
    //empty
}


void GEntityPlayer::EventHandler(SDL_Event* event)
{
    if(event->type == SDL_KEYDOWN)
    {
        switch(event->key.keysym.sym)
        {
            case SDLK_UP:
            {
                if(verticl == STILL)
                {
                    verticl = NEGATIVE;
                }

                break;
            }

            case SDLK_DOWN:
            {
                if(verticl == STILL)
                    verticl = POSITIVE;

                break;
            }

            case SDLK_LEFT:
            {
                if(horiztl == STILL)
                    horiztl = NEGATIVE;

                break;
            }

            case SDLK_RIGHT:
            {
                if(horiztl == STILL)
                    horiztl = POSITIVE;

                break;
            }

            default:
                break;
        }
    }
    else if(event->type == SDL_KEYUP)
    {
        switch(event->key.keysym.sym)
        {
            case SDLK_UP:
            {
                if(verticl == NEGATIVE)
                    verticl = STILL;

                break;
            }

            case SDLK_DOWN:
            {
                if(verticl == POSITIVE)
                    verticl = STILL;

                break;
            }

            case SDLK_LEFT:
            {
                if(horiztl == NEGATIVE)
                    horiztl = STILL;

                break;
            }

            case SDLK_RIGHT:
            {
                if(horiztl == POSITIVE)
                    horiztl = STILL;

                break;
            }

            default:
                break;
        }
    }
}

void GEntityPlayer::LoopHandler()
{
    switch(horiztl)
    {
        case NEGATIVE:
        {
            switch(verticl)
            {
                case POSITIVE:
                {
                    facing = SOUTHWEST;

                    break;
                }

                case NEGATIVE:
                {
                    facing = NORTHWEST;

                    break;
                }

                case STILL:
                {
                    facing = WEST;

                    break;
                }
            }

            break;
        }

        case POSITIVE:
        {
            switch(verticl)
            {
                case POSITIVE:
                {
                    facing = SOUTHEAST;

                    break;
                }

                case NEGATIVE:
                {
                    facing = NORTHEAST;

                    break;
                }

                case STILL:
                {
                    facing = EAST;

                    break;
                }
            }

            break;
        }

        case STILL:
        {
            switch(verticl)
            {
                case POSITIVE:
                {
                    facing = SOUTH;

                    break;
                }

                case NEGATIVE:
                {
                    facing = NORTH;

                    break;
                }
            }

            break;
        }
    }

    long elapsed = get_CurrentFrameTime() - get_LastFrameTime();
    double elapsedSeconds = elapsed / 1000.0;
    double frameAcceleration = elapsedSeconds * acceleration;
    double maxSpd = 500;

    switch(horiztl)
    {
        case NEGATIVE:
        {
            pos_X -= speed_X * elapsedSeconds;

            if(speed_X < maxSpd)
                speed_X += frameAcceleration;

            break;
        }

        case STILL:
        {
            speed_X = 0;

            break;
        }

        case POSITIVE:
        {
            pos_X += speed_X * elapsedSeconds;

            if(speed_X < maxSpd)
                speed_X += frameAcceleration;

            break;
        }
    }

    switch(verticl)
    {
        case NEGATIVE:
        {
            pos_Y -= speed_Y * elapsedSeconds;

            if(speed_Y < maxSpd)
                speed_Y += frameAcceleration;

            break;
        }

        case STILL:
        {
            speed_Y = 0;

            break;
        }

        case POSITIVE:
        {
            pos_Y += speed_Y * elapsedSeconds;

            if(speed_Y < maxSpd)
                speed_Y += frameAcceleration;

            break;
        }
    }

    if(speed_X > maxSpd)
        speed_X = maxSpd;
    if(speed_Y > maxSpd)
        speed_Y = maxSpd;

    if(pos_X > 1280)
        pos_X = 0;
}
