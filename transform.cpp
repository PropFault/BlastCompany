#include "transform.h"



Vec2 Transform::getScale() const
{
    return scale;
}

void Transform::setScale(const Vec2 &value)
{
    scale = value;
}

Transform &Transform::operator+=(const Transform &othr)
{
    this->position += othr.position;
    this->scale += othr.scale;
    return *this;
}

Transform::Transform(const Vec2 position, const Vec2 scale)
    :position(position), scale(scale)
{

}

Vec2 Transform::getPosition() const
{
    return position;
}

void Transform::setPosition(const Vec2 &value)
{
    position = value;
}
