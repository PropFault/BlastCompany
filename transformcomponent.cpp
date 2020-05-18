#include "transformcomponent.h"
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using namespace nlohmann;
const string TransformComponent::ARG_POSITION = "position";
const string TransformComponent::ARG_SCALE = "scale";

void TransformComponent::setPosition(const Vec2 &value)
{
    position = value;
}

void TransformComponent::setScale(const Vec2 &value)
{
    scale = value;
}

Vec2 TransformComponent::getPosition() const
{
    return position;
}

Vec2 TransformComponent::getScale() const
{
    return scale;
}

Component *TransformComponent::clone()
{
    return new TransformComponent();
}

void TransformComponent::_init(nlohmann::json j)
{
    json position = j[ARG_POSITION];
    json scale = j[ARG_POSITION];
    this->position = Vec2(position["x"],position["y"]);
    this->scale = Vec2(scale["x"], scale["y"]);
}

void TransformComponent::_deinit()
{
    this->position = Vec2(0,0);
    this->scale = Vec2(1,1);
}

TransformComponent::TransformComponent(const Vec2 position, const Vec2 scale)
    :Component("transform"), position(position), scale(scale)
{

}
