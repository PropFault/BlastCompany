#ifndef FUNCTIONMANAGER_H
#define FUNCTIONMANAGER_H
#include <unordered_map>
#include <functional>
#include "component.h"
#include <boost/any.hpp>
class FunctionManager
{
private:
    std::unordered_map<std::string, std::function<void(const boost::any&, Component::CID)>> functions;
public:
    FunctionManager();
    void registerFunction(const std::string &identifier, const std::function<void(const boost::any&, Component::CID)> &callback);
    void unregisterFunction(const std::string &identifier);
    bool call(const std::string identifier, const boost::any & data, Component::CID componentHint)const;
};

#endif // FUNCTIONMANAGER_H
