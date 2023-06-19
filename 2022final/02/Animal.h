#pragma once
using namespace std;
class Animal {
public:
    virtual void sing() = 0;
    virtual void swim() = 0;
    virtual ~Animal(){};
    Animal (){};
};