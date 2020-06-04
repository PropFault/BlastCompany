#include "systempipeline.h"

SystemPipeline::SystemPipeline()
{

}

SystemPipeline &SystemPipeline::add(System *system)
{
    this->pipeline.push_back(system);
    return *this;
}

void SystemPipeline::think(EntityComponentManager &ecm)
{
    System::DataPack pack;
    for(auto system : this->pipeline){
        const std::unordered_set<Component::CID> & compPack = ecm.lookupCIDsForType(system->getType());
        system->think(ecm, ecm.lookupCIDsForType(system->getType()), pack);
    }
}
