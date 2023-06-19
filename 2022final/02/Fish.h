#pragma once
#include"Animal.h"
using namespace std;

class Fish : public Animal{
public:
    string color;
    int type;
    Fish(int _type) : type(_type){
        if(type == 0){
            color = "Red";
        }
        else
            color = "Blue";
    }
    void sing(){
        cout << "Fish can not sing." << endl;
    }
    void swim(){
        cout << color << " fish is swimming." << endl;
    }
    ~Fish() {
        cout << color << " fish is gone." << endl;
    }
};