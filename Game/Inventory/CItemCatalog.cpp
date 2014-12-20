#include "CItemCatalog.h"

#include <iostream>
#warning iostream
void CItemCatalog::OnLoad(SDL_Renderer* rend_Used, std::string filename_ItemDef)
{
    SDL_Surface* dumbsurface = SDL_CreateRGBSurface(0, 48, 48, 32, 0x00ff0000, 0x0000ff00, 0xff, 0xff000000);

    SDL_FillRect(dumbsurface, nullptr, SDL_MapRGB(dumbsurface->format, 32, 192, 48));
    std::pair<std::string, SDL_Texture*> myTexturePair("chair", SDL_CreateTextureFromSurface(rend_Used, dumbsurface));
    std::cout << myTexturePair.first << ": " << myTexturePair.second << std::endl;
    map_ItemIcons.insert(myTexturePair);

    SDL_FillRect(dumbsurface, nullptr, SDL_MapRGB(dumbsurface->format, 48, 32, 192));
    myTexturePair = std::make_pair<std::string, SDL_Texture*>("axe", SDL_CreateTextureFromSurface(rend_Used, dumbsurface));
    std::cout << myTexturePair.first << ": " << myTexturePair.second << std::endl;
    map_ItemIcons.insert(myTexturePair);

    SDL_FreeSurface(dumbsurface);
}

SDL_Texture* CItemCatalog::get_ItemIcon(std::string itemName)
{
    std::unordered_map<std::string, SDL_Texture*>::iterator item = map_ItemIcons.find(itemName);

    if(item != map_ItemIcons.end())
        return item->second;

    return nullptr;
}
