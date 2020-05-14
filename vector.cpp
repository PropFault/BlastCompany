#include "vector.h"
#include <ostream>
using namespace std;

ostream& operator<<(ostream& os, const Vector& dt){
    return os << "("<< dt.x << "|"<<dt.y;
}


Vector::Vector(float x, float y):x(x),y(y){}
float Vector::getX() const{
    return this->x;
}
float Vector::getY() const{
    return this->y;
}
float Vector::setX(float x){
    this->x = x;
}
float Vector::setY(float y){
    this->y = y;
}
