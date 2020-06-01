#ifndef COMPONENTPLUGIN_H
#define COMPONENTPLUGIN_H
#include "entitycomponentmanager.h"
#include "sdlrenderer.h"
#include "window.h"
#include "systempipeline.h"
class ComponentPlugin{
public:
    virtual void onRegisterComponents(const Window &window, const SDLRenderer &renderer, EntityComponentManager &ecm) = 0;
    virtual void onRegisterSystems(SystemPipeline &pipeline) = 0;
};

#endif // COMPONENTPLUGIN_H
