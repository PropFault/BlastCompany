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
        auto& innerMap = dataPack.insertIfNotExists(comp->getEntity());
        Transform currentSum = any_cast<Transform>(innerMap.insertIfNotExists("transform", Transform()));
        currentSum += *comp;
        innerMap.get("transform") = currentSum;
    }
}
