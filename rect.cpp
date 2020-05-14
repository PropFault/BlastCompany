#include "rect.h"

Rect::Rect(const Vector &origin, float width, float height)
    :origin(origin), width(width), height(height)
{

}

Vector Rect::getOrigin() const
{
    return origin;
}

void Rect::setOrigin(const Vector &value)
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

