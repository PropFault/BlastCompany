#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include "hashmap.h"
#include "eid.h"
#include "component.h"
#include "entitycomponentmanager.h"
#include <unordered_set>
#include <any>
class System
{
private:
    std::string type;
public:
    typedef HashMap<Entity::EID, HashMap<std::string, std::any>> DataPack;
    System(const std::string &type);
    virtual void think(EntityComponentManager& ecs,const std::unordered_set<Component::CID>& typedComponents, DataPack& dataPack) = 0;
    std::string getType() const;
};

#endif // SYSTEM_H
