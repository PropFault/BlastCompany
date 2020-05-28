#include "transformcomponent.h"
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using namespace nlohmann;
const string TransformComponent::ARG_POSITION = "position";
const string TransformComponent::ARG_SCALE = "scale";


Component *TransformComponent::clone()
{
    return new TransformComponent();
}

void TransformComponent::_init(nlohmann::json j)
{
    json position = j[ARG_POSITION];
    json scale = j[ARG_SCALE];
    this->setPosition( Vec2(position["x"],position["y"]));
    this->setScale(Vec2(scale["x"], scale["y"]));
}

void TransformComponent::_deinit()
{
    this->setPosition(Vec2(0,0));
    this->setScale(Vec2(1,1));
}

TransformComponent::TransformComponent(const Vec2 position, const Vec2 scale)
    :Transform(position, scale), Component("transform")
{

}
