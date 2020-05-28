#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
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
    typedef std::unordered_map<Entity::EID, std::unordered_map<std::string, std::any>> DataPack;
    System(const std::string &type);
    virtual void think(EntityComponentManager& ecs,const std::unordered_set<Component::CID>& typedComponents, DataPack& dataPack) = 0;
    std::string getType() const;
};

#endif // SYSTEM_H
