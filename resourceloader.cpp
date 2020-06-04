#include "resourceloader.h"
#include <SDL2/SDL_image.h>
#include "context.h"
ResourceLoader::ResourceLoader(const SDLRenderer& renderer)
    :renderer(renderer)
{

}

SDL_Texture *ResourceLoader::loadSDLTexture(const std::string path)
{
    try {
        return this->loadedTextures.at(path);
    } catch (const std::out_of_range &std) {
        std::cout<<"LOADING UNLOADED TEXTURE "<<path <<std::endl;
        SDL_Texture* newTexture = NULL;
        SDL_Surface* surf = IMG_Load(path.c_str());
        if(surf != NULL){
            newTexture = SDL_CreateTextureFromSurface(this->renderer.getSdlRenderer(), surf);
            SDL_FreeSurface(surf);
            this->loadedTextures.emplace(path, newTexture);
            return newTexture;
        }else {
            throw std::runtime_error(std::string("COULD NOT LOAD IMAGE AT PATH")+path);
        }
    }
}
