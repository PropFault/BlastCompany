#include "texturerendersystem.h"

TextureRenderSystem::TextureRenderSystem(SDLRenderer &renderer)
    :System("texture"), renderer(renderer)
{

}

void TextureRenderSystem::think(EntityComponentManager &ecs, const std::vector<Component::CID> &typedComponents, System::DataPack &dataPack)
{
    for(auto cid : typedComponents){

    }
}
