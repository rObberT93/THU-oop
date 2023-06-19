#pragma once
#include<iostream>
#include "Fraction.h"
using namespace std;

template<class T>
class calculate{    
public:
    char expressionType;
    long long int x, y, z;
    T result;
    calculate(char e, long long int _x, long long int _y, long long int _z);   
};

template<>
calculate<int>::calculate(char e, long long int _x, long long int _y, long long int _z): expressionType(e), x(_x), y(_y), z(_z){
    if(expressionType == 'A'){
        result = x * x + y * y + z * z;
    }
    else if(expressionType == 'B') {
        result = x * y + y / z - x * z;
    }
    else {
        result = y * 3 * z - x * z /(y - 2) - x * y /(z + 1);
    }
}
ostream& operator<<(ostream& out, calculate<int> obj){
    out << obj.result;
    return out;
} 

template<>
calculate<Fraction>::calculate(char e, long long int _x, long long int _y, long long int _z) : expressionType(e), x(_x), y(_y), z(_z){
    if(expressionType == 'A'){
        result = x * x + y * y + z * z;
    }
    else if(expressionType == 'B') {
        result = Fraction(x * y, 1) + Fraction(y, z) - Fraction(x * z, 1);
    }
    else {
        result =  Fraction(y * 3 * z, 1) - Fraction(x * z , y - 2) - Fraction(x * y, (z + 1));
    }
}

ostream& operator<<(ostream& out, const calculate<Fraction>& obj){
    int temp_down = obj.result.down;
    int temp_up = obj.result.up;
    if(temp_down < 0){
        temp_up = - obj.result.up;
        temp_down = - obj.result.down;
    }
    if(temp_down == 1 || temp_down == -1) {
        out << temp_up;
        return out;
    }else {
        out << temp_up << "/" << temp_down;
        return out;
    }
}
