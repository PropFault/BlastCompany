#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H
#include <unordered_map>
#include <SDL2/SDL.h>
#include "sdlrenderer.h"
class ResourceLoader
{
private:
    std::unordered_map<std::string, SDL_Texture*> loadedTextures;
    const SDLRenderer& renderer;
public:
    ResourceLoader(const SDLRenderer& renderer);
    SDL_Texture *loadSDLTexture(const std::string path);
};

#endif // RESOURCELOADER_H
