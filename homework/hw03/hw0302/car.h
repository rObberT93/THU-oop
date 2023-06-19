#pragma once
#include <iostream>
#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
using namespace std;

class Car: public Vehicle{
    public:
        Car(int m_num, string m_engine): Vehicle(m_num, m_engine) {
            cout << "Finish building a car with " << m_num << " wheels and a " << m_engine << " engine." << endl;
        }
        void describe() {
            //cout << "Finish building a car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
            cout << "A car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
        }


};