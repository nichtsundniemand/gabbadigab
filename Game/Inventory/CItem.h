#ifndef CITEM_H
    #define CITEM_H

#include <string>
#include <vector>

#include "CItemContainer.h"

class CRoom;

enum itemGroupID
{
    GID_TOOL,
    GID_CLOTHING,
    GID_FURNITURE,
    GID_OTHER,
    GID_ITEMSTACK
};

class CItem
{
    protected:
        std::string itemName;

        itemGroupID groupID;

        CItem(std::string newName, itemGroupID newGroupID);

    public:
        unsigned char stackSize; //0 --> Item doesn't stack

        CItem(std::string newName);
        virtual ~CItem();

        std::string getItemID();
        itemGroupID getGroupID();
};

class CItemStack: public CItem
{
    public:
        CItemStack();

        CItemContainer stackContainer;
};


class CItemFurniture: public CItem
{
    public:
        CItemFurniture(std::string newName);
};

#endif
