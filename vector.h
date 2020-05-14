#ifndef POINT_H
#define POINT_H
#include <ostream>

class Vector
{
private:
    float x;
    float y;
public:
    Vector(float x, float y);
    float getX() const;
    float getY() const;
    float setX(float x);
    float setY(float y);
    friend std::ostream& operator<<(std::ostream& os, const Vector& dt);
};


#endif // POINT_H