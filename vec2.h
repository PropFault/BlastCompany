#ifndef POINT_H
#define POINT_H
#include <ostream>

class Vec2
{
private:
    float x;
    float y;
public:
    Vec2(float x, float y);
    float getX() const;
    float getY() const;
    float setX(float x);
    float setY(float y);
    friend std::ostream& operator<<(std::ostream& os, const Vec2& dt);
};


#endif // POINT_H
