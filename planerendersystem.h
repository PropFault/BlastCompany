#ifndef TEXTURERENDERSYSTEM_H
#define TEXTURERENDERSYSTEM_H
#include "system.h"
#include "sdlrenderer.h"
class PlaneRenderSystem : public System
{
private:
    SDLRenderer &renderer;
public:
    PlaneRenderSystem(SDLRenderer &renderer);

    // System interface
public:
    void think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, DataPack &dataPack);
};

#endif // TEXTURERENDERSYSTEM_H
