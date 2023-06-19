#pragma once
#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

template<typename T>
class Line {
public:
    T k;
    T b;
    Line(T k, T b = 0) : k(k), b(b) {}

    bool intersect(const Line& other) {
        if (k - other.k == 0) {
            return b - other.b == 1e-6;
        }
        return true;
    }

    void show() {
        cout << k << "," << b << endl;
    }

    bool operator<(const Line& other) const {
        return k < other.k;
    }
};
