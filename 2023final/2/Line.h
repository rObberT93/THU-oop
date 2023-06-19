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
        if (abs(k - other.k) < 1e-6) {
            return abs(b - other.b) < 1e-6;
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

template<>
class Line<int> {
public:
    int k;
    int b;
    Line(int k, int b = 0) : k(k), b(b) {}

    bool intersect(const Line& other) {
        if (abs(k - other.k) ==0 ) {
            return false;
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