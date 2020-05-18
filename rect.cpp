#include "rect.h"

Rect::Rect(const Vec2 &origin, float width, float height)
    :origin(origin), width(width), height(height)
{

}

Vec2 Rect::getOrigin() const
{
    return origin;
}

void Rect::setOrigin(const Vec2 &value)
{
    origin = value;
}

float Rect::getHeight() const
{
    return height;
}

void Rect::setHeight(float value)
{
    height = value;
}

float Rect::getWidth() const
{
    return width;
}

void Rect::setWidth(float value)
{
    width = value;
}

