#include "planecomponent.h"
#include "vec2.h"
#include <string>
using namespace std;
const string PlaneComponent::ARG_POSITION = "position";
const string PlaneComponent::ARG_SCALE = "scale";
const string PlaneComponent::ARG_TEXTURE = "texture";

Component::CID PlaneComponent::getTextureCID() const
{
    return textureCID;
}

PlaneComponent::PlaneComponent()
    :Component ("plane"), Rect(Vec2(0,0),1,1),textureCID(0){

}

void PlaneComponent::_init(nlohmann::json json)
{
    nlohmann::json posjson = json[ARG_POSITION];
    nlohmann::json scalejson = json[ARG_SCALE];
    this->textureCID = json[ARG_TEXTURE].get<Component::CID>();
    this->setOrigin(Vec2(posjson["x"],posjson["y"]));
    this->setWidth(scalejson["x"]);
    this->setHeight(scalejson["y"]);
}

void PlaneComponent::_deinit()
{
    this->textureCID=0;
    this->setOrigin(Vec2(0,0));
    this->setHeight(1);
    this->setWidth(1);
}

Component *PlaneComponent::clone()
{
    return new PlaneComponent();
}
