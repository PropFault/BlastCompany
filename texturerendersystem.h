#ifndef TEXTURERENDERSYSTEM_H
#define TEXTURERENDERSYSTEM_H
#include "system.h"
#include "sdlrenderer.h"
class TextureRenderSystem : public System
{
private:
    SDLRenderer &renderer;
public:
    TextureRenderSystem(SDLRenderer &renderer);

    // System interface
public:
    void think(EntityComponentManager &ecs, const std::vector<Component::CID> &typedComponents, DataPack &dataPack);
};

#endif // TEXTURERENDERSYSTEM_H
