#ifndef COMPONENTPLUGINLOADER_H
#define COMPONENTPLUGINLOADER_H
#include <string>
#include "entitycomponentmanager.h"
#include <nlohmann/json.hpp>
#include "systempipeline.h"
#include "componentplugin.h"
#include "sdlrenderer.h"
#include "window.h"
#include <vector>
#include <boost/shared_ptr.hpp>
#include "functionmanager.h"

class ComponentPluginLoader
{
private:
    static std::vector<boost::shared_ptr<ComponentPlugin>> loadedPlugins;
public:
    static void loadComponentPluginsFromDescriptor( const nlohmann::json &jsonFile, const Context &context);
};

#endif // COMPONENTPLUGINLOADER_H
