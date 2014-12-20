#include "CCursor.h"

CCursor::CCursor()
: thisCursor(CURSORTYPE_DEFAULT), posX(0), posY(0), leftClicked(false), rightClicked(false), middleClicked(false)
{
    //empty
}

CCursor::CCursor(CCursor& referenceCursor)
: thisCursor(CURSORTYPE_DEFAULT), posX(referenceCursor.posX), posY(referenceCursor.posY), leftClicked(referenceCursor.leftClicked), rightClicked(referenceCursor.rightClicked), middleClicked(referenceCursor.middleClicked)
{

}

CCursor::CCursor(CursorType newType)
: thisCursor(newType), posX(0), posY(0), leftClicked(false), rightClicked(false), middleClicked(false)
{
    //empty
}

CCursor::CCursor(CCursor& referenceCursor, CursorType newType)
: CCursor(referenceCursor)
{
    thisCursor = newType;
}

int CCursor::get_X()
{
    return posX;
}

int CCursor::get_Y()
{
    return posY;
}

bool CCursor::get_Left()
{
    return leftClicked;
}

bool CCursor::get_Right()
{
    return rightClicked;
}

bool CCursor::get_Middle()
{
    return middleClicked;
}

CursorType CCursor::get_Type()
{
    return thisCursor;
}

void CCursor::OnEvent(SDL_Event* event)
{
    switch(event->type)
    {
        case SDL_MOUSEMOTION:
        {
            posX = event->motion.x;
            posY = event->motion.y;

            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    leftClicked = true;
                    break;
                }

                case SDL_BUTTON_RIGHT:
                {
                    rightClicked = true;
                    break;
                }

                case SDL_BUTTON_MIDDLE:
                {
                    middleClicked = true;
                    break;
                }

                default:
                    break;
            }

            break;
        }

        case SDL_MOUSEBUTTONUP:
        {
            switch(event->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    leftClicked = false;
                    break;
                }

                case SDL_BUTTON_RIGHT:
                {
                    rightClicked = false;
                    break;
                }

                case SDL_BUTTON_MIDDLE:
                {
                    middleClicked = false;
                    break;
                }

                default:
                    break;
            }

            break;
        }

        default:
            break;
    }
}

CItemCursor::CItemCursor(CItem* attachingItem, unsigned int receiveSlot)
: CCursor(CURSORTYPE_ITEM), attachedItem(attachingItem), oldSlot(receiveSlot)
{
    //empty
}

CItemCursor::CItemCursor(CCursor& referenceCursor, CItem* attachingItem, unsigned int receiveSlot)
: CCursor(referenceCursor, CURSORTYPE_ITEM), attachedItem(attachingItem), oldSlot(receiveSlot)
{
    //empty
}

CItem* CItemCursor::get_Item()
{
    return attachedItem;
}

unsigned int CItemCursor::get_Slot()
{
    return oldSlot;
}
