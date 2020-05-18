#ifndef POSITIONSYSTEM_H
#define POSITIONSYSTEM_H
#include "component.h"
#include "system.h"

class TransformSystem : public System
{
public:
    TransformSystem();

    // System interface
public:
    void think(EntityComponentManager &ecs, const std::vector<Component::CID>& typedComponents, DataPack &dataPack);
};

#endif // POSITIONSYSTEM_H
