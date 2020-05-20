#include "planerendersystem.h"
#include "transform.h"
#include "planecomponent.h"
#include "eid.h"
#include <any>
#include "imagetexturecomponent.h"
using namespace std;
PlaneRenderSystem::PlaneRenderSystem(SDLRenderer &renderer)
    :System("plane"), renderer(renderer)
{

}

Rect getTransformedRect(const Rect &r, const Transform &t){
    Rect newRect(r);
    newRect.setOrigin(newRect.getOrigin() + t.getPosition());
    newRect.setWidth(newRect.getWidth() * t.getScale().getX());
    newRect.setHeight(newRect.getHeight() * t.getScale().getY());
    return newRect;
}

void PlaneRenderSystem::think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, System::DataPack &dataPack)
{
    for(auto cid : typedComponents){
        PlaneComponent* plane = ecs.lookupCID<PlaneComponent>(cid);
        Texture* texture = ecs.lookupCID<Texture>(plane->getTextureCID());
        Entity::EID entity = plane->getEntity();
        if(dataPack.containsKey(entity)&&dataPack.get(entity).containsKey("transform")){
            const Transform &accumTransform = any_cast<Transform>(dataPack.get(entity).get("transform"));
            this->renderer.renderRect(getTransformedRect(*plane, accumTransform),*texture);
        }else
            this->renderer.renderRect(*plane,*texture);

    }
}
