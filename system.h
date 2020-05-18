#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include "hashmap.h"
#include "eid.h"
#include "component.h"
#include "entitycomponentmanager.h"
#include <vector>
#include <unordered_set>

class System
{
private:
    std::string type;
public:
    typedef HashMap<Entity::EID, HashMap<std::string, std::unordered_set<Component::CID>>> DataPack;
    System(const std::string &type);
    virtual void think(EntityComponentManager& ecs,const std::vector<Component::CID>& typedComponents, DataPack& dataPack) = 0;
    std::string getType() const;
};

#endif // SYSTEM_H
