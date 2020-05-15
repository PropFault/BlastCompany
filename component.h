#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <nlohmann/json.hpp>
#include <random>

class Component
{
private:
    std::string name;
    unsigned long long id;
public:
    Component(const std::string name);
    virtual std::string getName()const;
    virtual Component* clone()=0;
    virtual void init(nlohmann::json json) = 0;
    virtual void deinit() = 0;
    unsigned long long getId();
    virtual ~Component(){}
};

#endif // COMPONENT_H
