#include "CGame.h"

void CGame::OnEvent()
{
    while(SDL_PollEvent(&theEvent))
    {
        Player1.OnEvent(&theEvent);
        cursor_Default->OnEvent(&theEvent);

        switch(theEvent.type)
        {
            case SDL_MOUSEBUTTONDOWN:
            {
                if(!myInvDisp.get_Hide())
                {
                    if(cursor_Default->get_Left())
                    {
                        unsigned int index = myInvDisp.coordsToIndex(cursor_Default->get_X(), cursor_Default->get_Y());

                        if((signed)index > -1)
                        {
                            CCursor* cursor_Old = cursor_Default;

                            CItem* item_Temp = myFirstInventory.inventoryItems.getItem(index);

                            if(item_Temp != nullptr)
                            {
                                cursor_Default = new CItemCursor(*cursor_Old, item_Temp, index);

                                delete cursor_Old;

                                myNewCursorDisplay.attachCursor(cursor_Default);

                                myFirstInventory.inventoryItems.removeItem(index);
                            }
                        }
                    }
                }

                break;
            }

            case SDL_MOUSEBUTTONUP:
            {
                if(cursor_Default->get_Type() == CURSORTYPE_ITEM)
                {
                    if(!cursor_Default->get_Left())
                    {
                        unsigned int slotIndex = myInvDisp.coordsToIndex(cursor_Default->get_X(), cursor_Default->get_Y());

                        CItem* cursorItem = ((CItemCursor*)cursor_Default)->get_Item();

                        if((signed)slotIndex == -1) //Mousepointer isn't over any inventory slot, Item will be return to where it came from
                        {
                            if(myFirstInventory.inventoryItems.getItem(((CItemCursor*)cursor_Default)->get_Slot()) == nullptr)
                            {
                                myFirstInventory.inventoryItems.insertItem(cursorItem, ((CItemCursor*)cursor_Default)->get_Slot());
                            }
                        }
                        else if((signed)slotIndex > -1) //Item was dropped over an inventory slot, either insert it, if that slot is empty, or swap
                        {
                            CItem* itemInSlot = myFirstInventory.inventoryItems.getItem(slotIndex);

                            if(itemInSlot == nullptr)//Slot is empty, just insert the item on the cursor into the inventory slot
                            {
                                myFirstInventory.inventoryItems.insertItem(cursorItem, slotIndex);
                            }
                            else //Slot is not empty, swap the item on the cursor with the on in the current slot
                            {
                                myFirstInventory.inventoryItems.removeItem(slotIndex);

                                myFirstInventory.inventoryItems.insertItem(cursorItem, slotIndex);

                                myFirstInventory.inventoryItems.insertItem(itemInSlot, ((CItemCursor*)cursor_Default)->get_Slot());
                            }
                        }

                        CCursor* cursor_Old = cursor_Default;

                        cursor_Default = new CCursor(*cursor_Old);

                        delete cursor_Old;

                        myNewCursorDisplay.attachCursor(cursor_Default);
                    }
                }

                break;
            }

            case SDL_KEYDOWN:
            {
                switch(theEvent.key.keysym.sym)
                {
                    case SDLK_SPACE:
                    {
                        CItem* theItem = myFirstInventory.inventoryItems.getItem(6);

                        if(theOnlyRoom.insertItem(theItem, 0))
                            myFirstInventory.inventoryItems.removeItem(6);
                        else
                        {
                            theOnlyRoom.itemSpace.insertItem(theItem, 0);
                            myFirstInventory.inventoryItems.removeItem(6);
                        }

                        break;
                    }

                    case SDLK_i:
                    {
                        myInvDisp.set_Hide(!myInvDisp.get_Hide());

                        break;
                    }

                    case SDLK_v:
                    {
                        for(unsigned int i = 0; i < myFirstInventory.inventoryItems.getSize(); i++)
                        {
                            CItem* theItem = myFirstInventory.inventoryItems.getItem(i);

                            if(theItem != nullptr)
                            {
                                if(theItem->getGroupID() == GID_ITEMSTACK)
                                {
                                    CItemStack* theStack = (CItemStack*)theItem;

                                    theStack->stackContainer.appendItem(new CItem("namae wa"));
                                }
                            }
                        }

                        break;
                    }

                    case SDLK_b:
                    {
                        myFirstInventory.inventoryItems.insertItem(&myNewStack, 6);

                        break;
                    }

                    case SDLK_m:
                    {
                        CItem* item1 = myFirstInventory.inventoryItems.getItem(5);
                        CItem* item2 = myFirstInventory.inventoryItems.getItem(12);

                        myFirstInventory.inventoryItems.removeItem(5);
                        myFirstInventory.inventoryItems.removeItem(12);

                        myFirstInventory.inventoryItems.insertItem(item2, 5);
                        myFirstInventory.inventoryItems.insertItem(item1, 12);

                        break;
                    }

                    case SDLK_ESCAPE:
                    {
                        running = false;

                        break;
                    }

                    default:
                        break;
                }

                break;
            }

            case SDL_QUIT:
            {
                running = false;

                break;
            }

            default:
                break;
        }
    }
}
