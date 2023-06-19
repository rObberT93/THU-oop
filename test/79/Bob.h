#pragma once
#include<iostream>
#include <vector>
#include"Robot.h"

using namespace std;

class Bob : public Robot{
public:
    int partNumber;
    Part **pb;
    int temp = 0;
    
    Bob(int _partNumber) : partNumber(_partNumber){
        pb = new Part*[partNumber];
    };
    bool is_full() {
        if(temp == partNumber) {
            return true;
        }
        return false;
    }

    void add_part(Part p) {
        pb[temp] = new Part(p);
        temp ++;
    }

    int run() {
        int res = 0;
        for(int i = 0; i < partNumber; i++) {
            res += pb[i]->id * pb[i]->id;
        }
        return res;
    }
    
    friend ostream& operator<<(ostream& out, const Bob& b) {
        out << "Build robot Bob";
        return out;
    }
    ~Bob() {
        for(int i = 0; i < partNumber; i++) {
            delete pb[i];
        }
        delete []pb;
    }

};