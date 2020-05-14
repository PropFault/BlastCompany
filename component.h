#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <nlohmann/json.hpp>

class Component
{
public:
    virtual std::string getName()=0;
    virtual Component* clone()=0;
    virtual init(nlohmann::json json) = 0;
    virtual deinit(nlohmann::json json) = 0;
    virtual ~Component(){}
};

#endif // COMPONENT_H
