#ifndef CITEMCONTAINER_H
    #define CITEMCONTAINER_H

#include <vector>

class CItem;

// FIXME (therufuser#1#): This classes implementation needs some rethinking.

class CItemContainer
{
    private:
        std::vector<CItem*> itemList;
        std::vector<unsigned int> indexList;

        void condense(); //remove unused space in itemList vector

    public:
        ~CItemContainer();

        unsigned int getSize();

        unsigned int appendItem(CItem* newItem);
        unsigned int insertItem(CItem* newItem, unsigned int pos);
        void removeItem(unsigned int itemIndex);

        CItem* getItem(unsigned int itemIndex);
};

#endif
