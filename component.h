#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <nlohmann/json.hpp>
#include <random>
#include "eid.h"
class Component
{
public:
    typedef unsigned long long CID;
private:
    std::string typeName;
    CID id;
    Entity::EID entity;
protected:
    virtual void _init(nlohmann::json json) = 0;
    virtual void _deinit() = 0;
public:

    Component(const std::string typeName);
    virtual std::string getTypeName()const;
    virtual Component* clone()=0;
    void init(Entity::EID eid, nlohmann::json json);
    void deinit();
    unsigned long long getId();
    virtual ~Component(){}
    Entity::EID getEntity() const;
    void regenerateId();
};

#endif // COMPONENT_H
