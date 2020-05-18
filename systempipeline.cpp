#include "systempipeline.h"

SystemPipeline::SystemPipeline()
{

}

SystemPipeline &SystemPipeline::add(System *system)
{
    this->pipeline.push_back(system);
}

void SystemPipeline::think(EntityComponentManager &ecm)
{
    System::DataPack pack;
    for(auto system : this->pipeline)
        system->think(ecm, pack);
}
