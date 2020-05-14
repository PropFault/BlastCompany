#ifndef QUAD_H
#define QUAD_H
#include "vector.h"
#include <ostream>

class Quad
{
private:
    Vector upLeft;
    Vector upRight;
    Vector downLeft;
    Vector downRight;
public:
    Quad(const Vector& upLeft, const Vector& upRight, const Vector& downLeft, const Vector& downRight);
    const Vector& getUpLeft()const;
    const Vector& getUpRight()const;
    const Vector& getDownLeft()const;
    const Vector& getDownRight()const;
    const void setUpLeft(const Vector& nVec);
    const void setUpRight(const Vector& nVec);
    const void setDownLeft(const Vector& nVec);
    const void setDownRight(const Vector& nVec);
    friend std::ostream& operator<<(std::ostream& out, const Quad& dat);
};

#endif // QUAD_H
