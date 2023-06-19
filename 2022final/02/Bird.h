#pragma once
#include"Animal.h"
using namespace std;

class Bird : public Animal{
public:
    string color;
    int type;
    Bird(int _type) : type(_type){
        if(type == 0){
            color = "Red";
        }
        else
            color = "Blue";
    }
    void sing(){
        cout << color <<" bird is singing." << endl;
    }
    void swim(){
        cout << "Bird can not swim." << endl;
    }
    ~Bird() {
        cout << color << " bird is gone." << endl;
    }
};