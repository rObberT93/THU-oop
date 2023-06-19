#pragma once
#include <iostream>
#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
using namespace std;

class Motor: public Vehicle {
    public:
        Motor(int m_num, string m_engine): Vehicle(m_num, m_engine) {
            cout << "Finish building a motor with " << m_num << " wheels and a " << m_engine << " engine." << endl;
        }
        void describe() {
            //cout << "Finish building a motor with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
            cout << "A motor with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
        }
        void sell();
};