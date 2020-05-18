#include "transformsystem.h"
#include "transformcomponent.h"
#include "entitycomponentmanager.h"
#include <string>
using namespace std;
TransformSystem::TransformSystem()
    :System("transform")
{

}

void TransformSystem::think(EntityComponentManager &ecs, const std::vector<Component::CID> &typedComponents, System::DataPack &dataPack)
{
    for(auto cid: typedComponents){
        TransformComponent* comp = ecs.lookupCID<TransformComponent>(cid);
        dataPack.insertIfNotExists(comp->getEntity()).insertIfNotExists("transform").insert(cid);
    }
}
