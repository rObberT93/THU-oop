#pragma once
#include<iostream>
#include "what.h"

using namespace std;

class Alien : public WhatCanMotion, public WhatCanSpeak{
public:
    string name;
    Alien(string _n) : name(_n){};
    void speak(){
        cout << name << " is speaking" << endl;
    }
    void stop(){
        cout << name << " stops" << endl;
    }
    void motion(){
        cout << name << " is moving" << endl;
    }
};