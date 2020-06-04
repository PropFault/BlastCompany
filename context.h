#ifndef CONTEXT_H
#define CONTEXT_H
#include "entitycomponentmanager.h"
#include "systempipeline.h"
#include "functionmanager.h"
#include "window.h"
#include "sdlrenderer.h"
#include "resourceloader.h"
class Context
{
private:
    Window &window;
    SDLRenderer &renderer;
    EntityComponentManager& ecm;
    SystemPipeline &systemPipeline;
    FunctionManager &funcMan;
    ResourceLoader &resourceLoader;
public:
    Context(Window &window, SDLRenderer &renderer, EntityComponentManager& ecm, SystemPipeline& systemPipeline, FunctionManager& funcMan, ResourceLoader &resourceLoader);
    EntityComponentManager &getEcm() const;
    void setEcm(const EntityComponentManager &value);
    SystemPipeline &getSp() const;
    void setSystemPipeline(const SystemPipeline &value);
    FunctionManager &getFuncMan() const;
    void setFuncMan(const FunctionManager &value);
    Window &getWindow() const;
    SDLRenderer &getRenderer() const;
    ResourceLoader &getResourceLoader() const;
};

#endif // CONTEXT_H
