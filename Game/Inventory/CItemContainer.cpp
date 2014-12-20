#include "CItemContainer.h"

CItemContainer::~CItemContainer()
{

}

unsigned int CItemContainer::getSize()
{
    return indexList.size();
}

unsigned int CItemContainer::appendItem(CItem* newItem)
{
    if(newItem != nullptr)
    {
        itemList.push_back(newItem);

        indexList.push_back(itemList.size() - 1);
    }
    else
        indexList.push_back(-1);

    return indexList.size() - 1;
}

unsigned int CItemContainer::insertItem(CItem* newItem, unsigned int pos)
{
    if(indexList.size() > 0)
    {
        std::vector<unsigned int>::iterator it_pos = indexList.begin() + pos;

        if(newItem != nullptr)
        {
            itemList.push_back(newItem);

            if((signed int)*it_pos == -1)
            #warning -1 is not an exclusive value, because unsigned int and stuff
                *it_pos = itemList.size() - 1;
            else
                indexList.insert(it_pos, itemList.size() - 1);
        }
        else
        {
            if((signed int)*it_pos != -1) //Don't need the -1 case, because the same value would be written anyway
            #warning -1 is not an exclusive value, because unsigned int and stuff
                indexList.insert(it_pos, -1);
        }
    }
    else
        appendItem(newItem);

    return pos;
}

CItem* CItemContainer::getItem(unsigned int itemIndex)
{
    unsigned int index = 0;
    if(itemIndex < indexList.size())
        index = indexList[itemIndex];
    else
        return nullptr;

    if((signed int)index == -1)
    #warning -1 is not unsigned.. beware of that
        return nullptr;
    else
        return itemList[index];
}

void CItemContainer::removeItem(unsigned int itemIndex)
{
    int index = indexList[itemIndex];

    if((signed int)index == -1)
        return;
    else
        indexList[itemIndex] = -1;
        itemList[index] = nullptr;

    // NOTE (therufuser#1#): Implement something like a delete stack
    //delete stack hold items that will be deleted and will be cleared every once in a while, but not upon every removeItem call
    #warning FIXME (therufuser#1#): No delete call guaranteed. Possible MemLeak.
}
