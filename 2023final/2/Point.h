#pragma once
#include <iostream>
#include <cmath>
#include "Line.h"
using namespace std;

template<typename T>
class Line;

template<typename T>
class Point {
public:
    T x;
    T y;
    Point(T x, T y) : x(x), y(y) {}

    void move(T dx, T dy) {
        x += dx;
        y += dy;
    }

    void show() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    bool check(Line<int> const& l){
        if(y = l.k * x + l.b){
            return true;
        }
        return false;
    }
};
