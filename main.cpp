#include <iostream>
#include "window.h"
#include "sdlrenderer.h"
#include "rect.h"
#include "hashmap.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "entitycomponentmanager.h"
#include "imagetexturecomponent.h"
#include "texture.h"
#include <SDL2/SDL_image.h>
using namespace std;

int main()
{
    EntityComponentManager ecs;
    EntityComponentManager::EID babiesFirstEntity = ecs.createNewEntity("TestEntity");
    cout<<"New entity with id: " << babiesFirstEntity << endl;
    Window window("Testscreen", 100,100,600,600, Window::Mode::WINDOWED);
    SDL_Renderer* sdlRenderer = window.createSdlRenderer();
    SDLRenderer renderer(sdlRenderer);

    ecs.registerBlueprint(new ImageTextureComponent(sdlRenderer));
    cout<<"nothing exploded yet."<<endl;
    nlohmann::json json;
    json[ImageTextureComponent::ARG_FILEPATH] = "sdl_logo.png";
    ecs.addComponentToEntity(babiesFirstEntity, Texture::COMPONENT_IDENTIFIER, json);
    for(EntityComponentManager::CID cid : ecs.lookupCIDsForType(Texture::COMPONENT_IDENTIFIER)){
            cout<<"ENTITY: " << ecs.lookupEntityName(babiesFirstEntity);
            cout<<"GOT COMPONENT WITH ID " << cid<<endl;
            cout<<"OBJ " << ecs.lookupCID<ImageTextureComponent>(cid)->getTypeName()<<endl;
            renderer.renderRect(Rect(Vector(0,0),1,1),*ecs.lookupCID<ImageTextureComponent>(cid));
    }
    renderer.present();
    cout<<SDL_GetError()<< "|" << IMG_GetError()<<endl;
    getchar();
    window.setMode(Window::Mode::FULLSCREEN);
    getchar();

    return 0;
}
