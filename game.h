#ifndef GAME_H
#define GAME_H
#include "window.h"
#include "sdlrenderer.h"
#include "entitycomponentmanager.h"
#include "systempipeline.h"
#include "functionmanager.h"
#include "context.h"
class Game{
public:
    virtual void start(Context &context) = 0;
    virtual void update()=0;
    virtual void end()=0;
};

#endif // GAME_H
