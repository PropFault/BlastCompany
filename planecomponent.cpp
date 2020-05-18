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
    :Component ("plane"), Rect(Vec2(0,0),1,1){

}

void PlaneComponent::_init(nlohmann::json json)
{
}
