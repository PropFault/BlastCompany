#include "component.h"
#include <random>
#include <iostream>
using namespace std;
unsigned long long Component::getId(){
    return this->id;
}
Component::Component(const std::string name)
    :name(name)
{
    random_device rd;
    unsigned int seed = rd();
    cout<<"Initing id with seed "<< seed <<"!"<<endl;
    default_random_engine engine(seed);
    uniform_int_distribution<long long unsigned> distrib(0, 0xFFFFFFFFFFFFFFFF);
    this->id = distrib(engine);
    cout<<"Created new component("<<this->name<<") ID:"<<this->id<<endl;
}

std::string Component::getName()const
{
    return this->name;
}
