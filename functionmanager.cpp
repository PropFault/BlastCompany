#include "functionmanager.h"
#include "component.h"
#include  <unordered_map>
#include <functional>
#include <boost/any.hpp>


FunctionManager::FunctionManager()
{

}

void FunctionManager::registerFunction(const std::string &identifier, const std::function<void(const boost::any&, Component::CID)> &callback)
{
    this->functions.emplace(identifier, callback);
}

void FunctionManager::unregisterFunction(const std::string &identifier)
{
    this->functions.erase(identifier);
}

bool FunctionManager::call(const std::string identifier, const boost::any &data, Component::CID componentHint)const
{
    try {
        this->functions.at(identifier)(data,componentHint);
    } catch (const std::out_of_range &ex) {
        return false;
    }
    return true;
}
