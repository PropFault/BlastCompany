#ifndef RECT_H
#define RECT_H
#include "vec2.h"

class Rect
{
private:
    float width;
    float height;
    Vec2 origin;
public:
    Rect(const Vec2& origin, float width, float height);
    Vec2 getOrigin() const;
    void setOrigin(const Vec2 &value);
    float getHeight() const;
    void setHeight(float value);
    float getWidth() const;
    void setWidth(float value);
};

#endif // RECT_H
