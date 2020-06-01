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
using namespace std;
using namespace nlohmann;
int main()
{
    boost::filesystem::path libPath("./components");
    /*boost::shared_ptr<ComponentPlugin> plugin;

    plugin = boost::dll::import<ComponentPlugin>(libPath/"testcomponent", "plugin", boost::dll::load_mode::append_decorations);*/
    fstream baseball("./game/entities/baseball.json");
    json baseJ;
    baseball >> baseJ;
    baseball.close();
    fstream f("./game/entities/testentity.json");
    json filej;
    f >> filej;
    f.close();
    fstream jsonF("./components/components.json");
    json componentDescriptor;
    jsonF >> componentDescriptor;
    jsonF.close();
    EntityComponentManager ecs;
    Entity::EID babiesFirstEntity = ecs.createNewEntity("TestEntity");

    cout<<"New entity with id: " << babiesFirstEntity << endl;
    Window window("Testscreen", 100,100,600,600, Window::Mode::WINDOWED);
    SDL_Renderer* sdlRenderer = window.createSdlRenderer();
    SDLRenderer renderer(sdlRenderer);
    SystemPipeline pipeline;
    pipeline.add(new TransformSystem());
    ComponentPluginLoader::loadComponentPluginsFromDescriptor(renderer, window, componentDescriptor, ecs, pipeline);
    pipeline.add(new PlaneRenderSystem(renderer));




    ecs.registerBlueprint(new ImageTextureComponent(sdlRenderer));
    ecs.registerBlueprint(new TransformComponent());
    ecs.registerBlueprint(new PlaneComponent());
    cout<<"nothing exploded yet."<<endl;
    nlohmann::json json;
    /*json[ImageTextureComponent::ARG_FILEPATH] = "sdl_logo.png";
    ecs.addComponentToEntity(babiesFirstEntity, Texture::COMPONENT_IDENTIFIER, json);*/
    ecs.createEntityFromFile(filej);
    ecs.createEntityFromFile(baseJ);
    ecs.createEntityFromFile(baseJ);

    ecs.createEntityFromFile(baseJ);

    for(auto cid : ecs.lookupCIDsForType("transform")){
        Transform* transform = ecs.lookupCID<Transform>(cid);
        transform->setPosition(transform->getPosition() + Vec2(rand()%10/100.0f, 0.0));
    }

    ecs.createEntityFromFile(baseJ);

    SDL_Event evt;
    clock_t measure = clock();
    while(true){
        SDL_PollEvent(&evt);
        if(evt.type == SDL_QUIT)
            break;
        pipeline.think(ecs);
        renderer.present();
        while(((clock()-measure)/(double)CLOCKS_PER_SEC)<0.006f){};
        measure = clock();
    }



    cout<<SDL_GetError()<< "|" << IMG_GetError()<<endl;


    return 0;
}
