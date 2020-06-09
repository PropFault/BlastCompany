#ifndef COMPONENTPLUGIN_H
#define COMPONENTPLUGIN_H
#include "entitycomponentmanager.h"
#include "context.h"
class ComponentPlugin{
public:
    virtual void onRegisterComponents(const Context &context) = 0;
    virtual void onRegisterSystems(SystemPipeline &pipeline, const Context &context) = 0;
};

#endif // COMPONENTPLUGIN_H
