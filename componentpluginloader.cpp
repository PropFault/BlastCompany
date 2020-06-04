#include "componentpluginloader.h"
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include <boost/dll/import.hpp>
#include "componentplugin.h"
#include "sdlrenderer.h"
#include "window.h"
#include "context.h"
using namespace boost::filesystem;


std::vector<boost::shared_ptr<ComponentPlugin>> ComponentPluginLoader::loadedPlugins;

void ComponentPluginLoader::loadComponentPluginsFromDescriptor( const nlohmann::json &jsonFile, const Context &context)
{

    boost::filesystem::path libPath = jsonFile.at("componentDirectory");
    for(auto& thing : jsonFile.at("components")){
        std::cout<<libPath/thing<<std::endl;
        boost::shared_ptr<ComponentPlugin> plugin = boost::dll::import<ComponentPlugin>(libPath/thing, "plugin", boost::dll::load_mode::append_decorations);
        ComponentPluginLoader::loadedPlugins.push_back(plugin);
       // std::cout<<"USED: " <<ComponentPluginLoader::loadedPlugins.at(ComponentPluginLoader::loadedPlugins.size()-1).use_count()<<std::endl;
        ComponentPlugin* plug = &*plugin;
        plug->onRegisterComponents(context);
        plug->onRegisterSystems(context.getSp());
    }
}
