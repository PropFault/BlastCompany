#ifndef NAMECOMPONENT_H
#define NAMECOMPONENT_H
#include "component.h"
#include <string>
class NameComponent : public Component
{
private:
    std::string typeName;
public:
    NameComponent();

    // Component interface
public:
    Component *clone();
private:
    void _init(nlohmann::json json);
    void _deinit();
public:
    std::string getName()const;
};

#endif // NAMECOMPONENT_H
