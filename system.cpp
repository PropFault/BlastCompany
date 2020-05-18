#include "system.h"


std::string System::getType() const
{
    return type;
}

System::System(const std::string &type)
    :type(type)
{

}

void System::DataPack::add(Entity::EID eid, std::string message, Component::CID)
{
    if(!this->data.containsKey(eid))
        this->data.insert(eid, HashMap<std::string,Component::CID>());


}
