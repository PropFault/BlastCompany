#include <iostream>
#include "window.h"
#include "sdlrenderer.h"
#include "rect.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "entitycomponentmanager.h"
#include "imagetexturecomponent.h"
#include "texture.h"
#include <SDL2/SDL_image.h>
#include <fstream>
#include <nlohmann/json.hpp>
#include "transformcomponent.h"
#include "eid.h"
#include "systempipeline.h"
#include "transformsystem.h"
#include "planerendersystem.h"
#include "planecomponent.h"
#include <unistd.h>
#include <boost/dll/import.hpp>
#include "componentplugin.h"
#include "componentpluginloader.h"
#include "game.h"
#include "functionmanager.h"
#include "context.h"
#include "resourceloader.h"
using namespace std;
using namespace nlohmann;


int main()
{
    boost::filesystem::path gamePath = ("./game/bin/Game");
    EntityComponentManager ecs;
    FunctionManager funcMan;
    fstream jsonF("./components/components.json");
    json componentDescriptor;
    jsonF >> componentDescriptor;
    jsonF.close();
    Window window("Testscreen", 100,100,1270,720, Window::Mode::WINDOWED);
    std::cout<<SDL_GetError()<<std::endl;
    SDLRenderer renderer(window.createSdlRenderer());
    ResourceLoader resourceLoader(renderer);
    ecs.registerBlueprint(new ImageTextureComponent(renderer.getSdlRenderer()));
    ecs.registerBlueprint(new TransformComponent());
    ecs.registerBlueprint(new PlaneComponent());
    SystemPipeline pipeline;
    SDL_Event evt;

    Context context(window, renderer, ecs, pipeline, funcMan, resourceLoader,evt);
    pipeline.add(new TransformSystem());
    ComponentPluginLoader::loadComponentPluginsFromDescriptor(componentDescriptor, context);
    boost::shared_ptr<Game> game = boost::dll::import<Game>(gamePath, "game", boost::dll::load_mode::append_decorations);
    game->start(context);
    pipeline.add(new PlaneRenderSystem(renderer));





    clock_t measure = clock();
    while(true){
        SDL_PollEvent(&evt);
        if(evt.type == SDL_QUIT)
            break;
        game->update();
        pipeline.think(ecs);
        renderer.present();
        while(((clock()-measure)/(double)CLOCKS_PER_SEC)<0.006f){};
        measure = clock();
    }

    game->end();
    cout<<SDL_GetError()<< "|" << IMG_GetError()<<endl;


    return 0;
}
