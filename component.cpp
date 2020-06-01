#include "component.h"
#include <random>
#include <iostream>
using namespace std;
unsigned long long Component::getId(){
    return this->id;
}


Entity::EID Component::getEntity() const
{
    return entity;
}

void Component::regenerateId()
{
    random_device rd;
    unsigned int seed = rd();
    cout<<"Initing id with seed "<< seed <<"!"<<endl;
    default_random_engine engine(seed);
    uniform_int_distribution<long long unsigned> distrib(0, 0xFFFFFFFFFFFFFFFF);
    this->id = distrib(engine);
    cout<<"Created new component("<<this->typeName<<") ID:"<<this->id<<endl;
}

Component::Component(const std::string name)
    :typeName(name), entity(0)
{
    this->regenerateId();

}



std::string Component::getTypeName()const
{
    return this->typeName;
}

void Component::init(Entity::EID eid, nlohmann::json json)
{
    this->entity = eid;
    this->_init(json);
}

void Component::deinit()
{
    this->entity = 0;
    this->_deinit();
}
