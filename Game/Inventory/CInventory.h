#ifndef CINVENTORY_H
    #define CINVENTORY_H

#include <vector>

#include "CItemContainer.h"

class CInventory
{
    private:

    public:
        CInventory();

        CItemContainer inventoryItems;
};

#endif

// TODO (therufuser#2#): What happens, if the inventory contains more than 14 items?
