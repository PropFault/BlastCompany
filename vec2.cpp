#include "vec2.h"
#include <ostream>
using namespace std;

ostream& operator<<(ostream& os, const Vec2& dt){
    return os << "("<< dt.x << "|"<<dt.y;
}


Vec2::Vec2(float x, float y):x(x),y(y){}
float Vec2::getX() const{
    return this->x;
}
float Vec2::getY() const{
    return this->y;
}
void Vec2::setX(float x){
    this->x = x;
}
void Vec2::setY(float y){
    this->y = y;
}

Vec2 &Vec2::operator+=(const Vec2 &othr)
{
    this->x += othr.x;
    this->y += othr.y;
    return *this;
}

Vec2 Vec2::operator+(const Vec2 &othr)
{
    return Vec2(*this)+=othr;
}
