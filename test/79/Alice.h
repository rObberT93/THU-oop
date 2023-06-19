#pragma once
#include<iostream>
#include <vector>
#include"Robot.h"

using namespace std;

class Alice : public Robot{
public:
    int partNumber;
    Part **pa;
    int temp = 0;
    
    Alice(int _partNumber) : partNumber(_partNumber){
        pa = new Part*[partNumber];
    }
    bool is_full() {
        if(temp == partNumber) {
            return true;
        }
        return false;
    }

    void add_part(Part p) {
        pa[temp] = new Part(p);
        temp ++;
    }

    int run() {
        int res = 0;
        for(int i = 0; i < partNumber; i++) {
            res += pa[i]->id;
        }
        return res;
    }

    friend ostream& operator<<(ostream& out, const Alice& a) {
        out << "Build robot Alice";
        return out;
    }
    
    ~Alice() {
        for(int i = 0; i < partNumber; i++) {
            delete pa[i];
        }
        delete []pa;
    }

};