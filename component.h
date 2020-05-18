#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <nlohmann/json.hpp>
#include <random>

class Component
{
private:
    std::string typeName;
    unsigned long long id;
public:
    Component(const std::string typeName);
    virtual std::string getTypeName()const;
    virtual Component* clone()=0;
    virtual void init(nlohmann::json json) = 0;
    virtual void deinit() = 0;
    unsigned long long getId();
    virtual ~Component(){}
};

#endif // COMPONENT_H
