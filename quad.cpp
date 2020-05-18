#include "quad.h"



Quad::Quad(const Vec2 &upLeft, const Vec2 &upRight, const Vec2 &downLeft, const Vec2 &downRight)
    :upLeft(upLeft), upRight(upRight), downLeft(downLeft), downRight(downRight){}

const Vec2 &Quad::getUpLeft() const
{
    return this->upLeft;
}

const Vec2 &Quad::getUpRight() const
{
    return this->upRight;
}

const Vec2 &Quad::getDownLeft() const
{
    return this->downLeft;
}

const Vec2 &Quad::getDownRight() const
{
    return this->downRight;
}

const void Quad::setUpLeft(const Vec2 &nVec)
{
    this->upLeft = nVec;
}

const void Quad::setUpRight(const Vec2 &nVec)
{
    this->upRight = nVec;
}

const void Quad::setDownLeft(const Vec2 &nVec)
{
    this->downLeft = nVec;
}

const void Quad::setDownRight(const Vec2 &nVec)
{
    this->downRight = nVec;
}

std::ostream &operator<<(std::ostream &out, const Quad &dat)
{
    return out<<"q(ul"<<dat.upLeft<<",ur"<<dat.upRight<<",dl"<<dat.downLeft<<",dr"<<dat.downRight<<")";
}
