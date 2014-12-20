#include "CItem.h"

#include "Game/Room/CRoom.h"

/* CItem ---------------------------------- */
CItem::CItem(std::string newName)
{
    itemName = newName;

    groupID = GID_OTHER;
}

CItem::CItem(std::string newName, itemGroupID newGroupID)
{
    itemName = newName;

    groupID = newGroupID;
}

CItem::~CItem()
{
    itemName = "";
}

std::string CItem::getItemID()
{
    return itemName;
    // FIXME (therufuser#1#): Return itemID, not the name
}

itemGroupID CItem::getGroupID()
{
    return groupID;
}

/* CItemStack ----------------------------- */
CItemStack::CItemStack()
// FIXME (therufuser#1#): Stack should be initialized with a certain type of item.
: CItem("stack'n'break", GID_ITEMSTACK)
{
    //empty
}

/* CItemFurniture ------------------------- */
CItemFurniture::CItemFurniture(std::string newName)
: CItem(newName, GID_FURNITURE)
{}
