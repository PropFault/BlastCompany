#include "context.h"

SystemPipeline &Context::getSp() const
{
    return systemPipeline;
}

void Context::setSystemPipeline(const SystemPipeline &value)
{
    systemPipeline = value;
}

FunctionManager &Context::getFuncMan() const
{
    return funcMan;
}

void Context::setFuncMan(const FunctionManager &value)
{
    funcMan = value;
}

Window &Context::getWindow() const
{
    return window;
}



SDLRenderer &Context::getRenderer() const
{
    return renderer;
}


Context::Context(Window &window, SDLRenderer &renderer, EntityComponentManager &ecm, SystemPipeline &sp, FunctionManager &funcMan, ResourceLoader &resourceLoader)
    :window(window), renderer(renderer), ecm(ecm), systemPipeline(sp), funcMan(funcMan), resourceLoader(resourceLoader){}

ResourceLoader &Context::getResourceLoader() const
{
    return resourceLoader;
}


EntityComponentManager &Context::getEcm() const
{
    return ecm;
}

void Context::setEcm(const EntityComponentManager &value)
{
    ecm = value;
}
