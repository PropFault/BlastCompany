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
    void setX(float x);
    void setY(float y);
    friend std::ostream& operator<<(std::ostream& os, const Vec2& dt);
    Vec2 & operator+=(const Vec2 &othr);
    Vec2 operator+(const Vec2 &othr);
};


#endif // POINT_H
