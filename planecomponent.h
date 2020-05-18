#ifndef PLANECOMPONENT_H
#define PLANECOMPONENT_H
#include "rect.h"
#include "component.h"
#include <string>

class PlaneComponent : public Component, public Rect
{
private:
    Component::CID textureCID;
public:
    PlaneComponent();
    const static std::string ARG_POSITION;
    const static std::string ARG_SCALE;
    const static std::string ARG_TEXTURE;
    // Component interface
private:
    void _init(nlohmann::json json);
    void _deinit();

public:
    Component *clone();
    Component::CID getTextureCID() const;
};

#endif // PLANECOMPONENT_H
