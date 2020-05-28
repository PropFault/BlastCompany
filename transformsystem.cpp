#include "transformsystem.h"
#include "transformcomponent.h"
#include "entitycomponentmanager.h"
#include "transform.h"
#include <string>
using namespace std;
TransformSystem::TransformSystem()
    :System("transform")
{

}

void TransformSystem::think(EntityComponentManager &ecs, const std::unordered_set<Component::CID> &typedComponents, System::DataPack &dataPack)
{
    for(auto cid: typedComponents){
        TransformComponent* comp = ecs.lookupCID<TransformComponent>(cid);
        auto& innerMap = dataPack[comp->getEntity()];
        innerMap.insert(std::pair("transform", Transform(Vec2(0,0),Vec2(0,0))));
        Transform currentSum = any_cast<Transform>(innerMap["transform"]);
        currentSum += *comp;
        innerMap.at("transform") = currentSum;
    }
}
