#include "quad.h"



Quad::Quad(const Vector &upLeft, const Vector &upRight, const Vector &downLeft, const Vector &downRight)
    :upLeft(upLeft), upRight(upRight), downLeft(downLeft), downRight(downRight){}

const Vector &Quad::getUpLeft() const
{
    return this->upLeft;
}

const Vector &Quad::getUpRight() const
{
    return this->upRight;
}

const Vector &Quad::getDownLeft() const
{
    return this->downLeft;
}

const Vector &Quad::getDownRight() const
{
    return this->downRight;
}

const void Quad::setUpLeft(const Vector &nVec)
{
    this->upLeft = nVec;
}

const void Quad::setUpRight(const Vector &nVec)
{
    this->upRight = nVec;
}

const void Quad::setDownLeft(const Vector &nVec)
{
    this->downLeft = nVec;
}

const void Quad::setDownRight(const Vector &nVec)
{
    this->downRight = nVec;
}

std::ostream &operator<<(std::ostream &out, const Quad &dat)
{
    return out<<"q(ul"<<dat.upLeft<<",ur"<<dat.upRight<<",dl"<<dat.downLeft<<",dr"<<dat.downRight<<")";
}
