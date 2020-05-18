#ifndef QUAD_H
#define QUAD_H
#include "vec2.h"
#include <ostream>

class Quad
{
private:
    Vec2 upLeft;
    Vec2 upRight;
    Vec2 downLeft;
    Vec2 downRight;
public:
    Quad(const Vec2& upLeft, const Vec2& upRight, const Vec2& downLeft, const Vec2& downRight);
    const Vec2& getUpLeft()const;
    const Vec2& getUpRight()const;
    const Vec2& getDownLeft()const;
    const Vec2& getDownRight()const;
    const void setUpLeft(const Vec2& nVec);
    const void setUpRight(const Vec2& nVec);
    const void setDownLeft(const Vec2& nVec);
    const void setDownRight(const Vec2& nVec);
    friend std::ostream& operator<<(std::ostream& out, const Quad& dat);
};

#endif // QUAD_H
