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
using namespace std;
using namespace nlohmann;
int main()
{
    fstream f("./game/entities/testentity.json");
    json filej;
    f >> filej;
    f.close();
    EntityComponentManager ecs;
    Entity::EID babiesFirstEntity = ecs.createNewEntity("TestEntity");
    cout<<"New entity with id: " << babiesFirstEntity << endl;
    Window window("Testscreen", 100,100,600,600, Window::Mode::WINDOWED);
    SDL_Renderer* sdlRenderer = window.createSdlRenderer();
    SDLRenderer renderer(sdlRenderer);

    ecs.registerBlueprint(new ImageTextureComponent(sdlRenderer));
    ecs.registerBlueprint(new TransformComponent());
    ecs.registerBlueprint(new PlaneComponent());
    cout<<"nothing exploded yet."<<endl;
    nlohmann::json json;
    /*json[ImageTextureComponent::ARG_FILEPATH] = "sdl_logo.png";
    ecs.addComponentToEntity(babiesFirstEntity, Texture::COMPONENT_IDENTIFIER, json);*/
    ecs.createEntityFromFile(filej);

    SystemPipeline pipeline;
    pipeline.add(new TransformSystem());
    pipeline.add(new PlaneRenderSystem(renderer));

    pipeline.think(ecs);


    renderer.present();
    cout<<SDL_GetError()<< "|" << IMG_GetError()<<endl;

    usleep(1000*10000);

    return 0;
}
