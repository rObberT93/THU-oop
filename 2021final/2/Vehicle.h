#pragma once
#include<iostream>

using namespace std;

class Vehicle{
public:
    int maxWheel;
    int maxWing;
    int tempWheel = 0;
    int tempWing = 0;
    void set_max_wheel_num(int _wheel){
        maxWheel = _wheel;
    }
    void set_max_wing_num(int _wing) {
        maxWing = _wing;
    }
    void add_wing(){
        tempWing++;
    }
    void add_wheel(){
        tempWheel++;
    }
    bool finished() {
        if(tempWheel >= maxWheel && tempWing >= maxWing) 
            return true;
        return false;
    }
    void run() {
        cout << "I am running" << endl; 
    }
};