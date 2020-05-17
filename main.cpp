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
using namespace std;

int main()
{
    EntityComponentManager ecs;
    EntityComponentManager::EID babiesFirstEntity = ecs.createNewEntity();
    cout<<"New entity with id: " << babiesFirstEntity << endl;
    Window window("Testscreen", 100,100,600,600, Window::Mode::WINDOWED);
    SDL_Renderer* sdlRenderer = window.createSdlRenderer();
    SDLRenderer renderer(sdlRenderer);
    renderer.present();

    ecs.registerBlueprint(new ImageTextureComponent(sdlRenderer));
    cout<<"nothing exploded yet."<<endl;
    ecs.addComponentToEntity(babiesFirstEntity, Texture::COMPONENT_IDENTIFIER, nlohmann::json());
    for(EntityComponentManager::CID cid : ecs.lookupCIDsForType(Texture::COMPONENT_IDENTIFIER)){
            cout<<"GOT COMPONENT WITH ID " << cid<<endl;
            cout<<"OBJ " << ecs.lookupCID(cid)->getName()<<endl;
    }
    getchar();
    return 0;
}
