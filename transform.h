#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vec2.h"
class Transform
{
private:
    Vec2 position;
    Vec2 scale;
public:
    Transform(const Vec2 position = Vec2(0,0), const Vec2 scale = Vec2(1,1));
    Vec2 getPosition() const;
    void setPosition(const Vec2 &value);
    Vec2 getScale() const;
    void setScale(const Vec2 &value);
    Transform& operator+=(const Transform &othr);
};

#endif // TRANSFORM_H
