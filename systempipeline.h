#ifndef SYSTEMPIPELINE_H
#define SYSTEMPIPELINE_H
#include "system.h"
#include <vector>
#include "entitycomponentmanager.h"
class SystemPipeline
{
private:
    std::vector<System*> pipeline;
public:
    SystemPipeline();
    SystemPipeline& add(System* system); //pointers passed forefit ownership of the object. will be destroyed when the pipeline gets destroyed.
    void think(EntityComponentManager &ecm);
};

#endif // SYSTEMPIPELINE_H
