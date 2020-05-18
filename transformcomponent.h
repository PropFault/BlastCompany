#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "component.h"
#include "vec2.h"
#include <string>

class TransformComponent : public Component
{
private:
    Vec2 position;
    Vec2 scale;
public:
    const static std::string ARG_POSITION;
    const static std::string ARG_SCALE;
    TransformComponent(const Vec2 position = Vec2(0,0), const Vec2 scale = Vec2(1,1));
    void setPosition(const Vec2 &value);
    void setScale(const Vec2 &value);
    Vec2 getPosition() const;
    Vec2 getScale() const;

    // Component interface
public:
    Component *clone();
private:
    void _init(nlohmann::json json);
    void _deinit();
};

#endif // TRANSFORMCOMPONENT_H
