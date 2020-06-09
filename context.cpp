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


SDL_Event &Context::getEvent() const
{
    return event;
}

void Context::setEvent(const SDL_Event &value)
{
    event = value;
}

Context::Context(Window &window, SDLRenderer &renderer, EntityComponentManager &ecm, SystemPipeline &sp, FunctionManager &funcMan, ResourceLoader &resourceLoader, SDL_Event &event)
    :window(window), renderer(renderer), ecm(ecm), systemPipeline(sp), funcMan(funcMan), resourceLoader(resourceLoader), event(event){}

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
