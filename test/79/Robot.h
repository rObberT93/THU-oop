#pragma once
#include<iostream>
#include"Part.h"

using namespace std;

class Robot{
public:
    virtual bool is_full() = 0;
    virtual void add_part(Part p) = 0;
    virtual int run() = 0;
};