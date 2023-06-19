#pragma once
#include <iostream>
#include "wheel.h"
#include "engine.h"
using namespace std;

class Vehicle {
    protected:
        Engine e;
        Wheel w;
    public:
        Vehicle(int, string);
        void describe();

};