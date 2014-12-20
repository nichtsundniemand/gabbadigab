#ifndef CITEMCATALOG_H
    #define CITEMCATALOG_H

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

class CItemCatalog
{
    private:
        std::unordered_map<std::string, SDL_Texture*> map_ItemIcons;
        //unordered map, because random access mostly

    public:

        void OnLoad(SDL_Renderer* rend_Attaching, std::string filename_ItemDef);

        SDL_Texture* get_ItemIcon(std::string itemName);
};

#endif
