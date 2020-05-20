#include "system.h"


std::string System::getType() const
{
    return type;
}

System::System(const std::string &type)
    :type(type)
{

}
