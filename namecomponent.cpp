#include "namecomponent.h"
#include <iostream>
NameComponent::NameComponent()
    :Component("name"),typeName("UNNAMED")
{

}

Component *NameComponent::clone()
{
    return new NameComponent;
}

void NameComponent::_init(nlohmann::json json)
{
    std::cout<<json<<std::endl;
    this->typeName = json["name"].get<std::string>();
}

void NameComponent::_deinit()
{
    this->typeName = "UNNAMED";
}

std::string NameComponent::getName()const
{
    return this->typeName;
}
