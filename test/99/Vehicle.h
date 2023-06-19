#pragma once
#include<iostream>

using namespace std;

class Vehicle{
    int wheelNum = 0;
    int wingNum = 0;
    int maxWheel;
    int maxWing;
public:
    void add_wing(){
        wingNum ++;
    }
    void add_wheel(){
        wheelNum++;
    }
    void set_max_wheel_num(int _mwheel){
        maxWheel = _mwheel;
    }
    void set_max_wing_num(int _mwing){
        maxWing = _mwing;
    }

    virtual void run() {
        cout << "I am running " << endl;
    }

    bool finished(){
        if((wheelNum >= maxWheel) && (wingNum >= maxWing))
            return true;
        return false;
    }
    

};