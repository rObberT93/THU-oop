#pragma once
#include "cmath"
#include<iostream>
using namespace std;

class Fraction{
public:
    long long int gcd(long long int a, long long int b){
        return b ? gcd(b, a % b) : a;
    }
    long long int up;
    long long int down;
    Fraction(){};
    Fraction(long long int _up, long long int _down = 1) : up(_up), down(_down){
        long long int div = gcd(_up, _down);
        up /= div;
        down /= div;
    }
    Fraction operator+(const Fraction& b) {
        return Fraction(up * b.down + b.up * down, down * b.down);
    }
    Fraction operator-(const Fraction& b) {
        return Fraction(up * b.down - b.up * down, down * b.down);
    }
    Fraction operator*(const Fraction& b) {
        return Fraction(up * b.up, down * b.down);
    }
    Fraction operator/(Fraction& b) {
        return Fraction(up * b.down, down * b.up);
    }
};

