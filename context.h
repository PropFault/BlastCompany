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
    SDL_Event &event;

    Context(Window &window, SDLRenderer &renderer, EntityComponentManager& ecm, SystemPipeline& systemPipeline, FunctionManager& funcMan, ResourceLoader &resourceLoader, SDL_Event &event);
    EntityComponentManager &getEcm() const;
    void setEcm(const EntityComponentManager &value);
    SystemPipeline &getSp() const;
    void setSystemPipeline(const SystemPipeline &value);
    FunctionManager &getFuncMan() const;
    void setFuncMan(const FunctionManager &value);
    Window &getWindow() const;
    SDLRenderer &getRenderer() const;
    ResourceLoader &getResourceLoader() const;
    SDL_Event &getEvent() const;
    void setEvent(const SDL_Event &value);
};

#endif // CONTEXT_H
