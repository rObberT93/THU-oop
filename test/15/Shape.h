#pragma once
#include<iostream>

using namespace std;

class Shape{
public:
    double width;
    double height;
    double radius;
    virtual double getArea() = 0;
};

class Rectangle : public Shape{
public:
    double width;
    double height;
    Rectangle(double w, double h):width(w), height(h){}
    double getArea(){
        return width * height;
    }
};

class Circle : public Shape{
public:
    double radius;
    Circle(double r):radius(r){}
    double getArea(){
        return 3.14 * radius * radius;
    }

};