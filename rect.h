#ifndef RECT_H
#define RECT_H
#include "vector.h"

class Rect
{
private:
    float width;
    float height;
    Vector origin;
public:
    Rect(const Vector& origin, float width, float height);
    Vector getOrigin() const;
    void setOrigin(const Vector &value);
    float getHeight() const;
    void setHeight(float value);
    float getWidth() const;
    void setWidth(float value);
};

#endif // RECT_H
