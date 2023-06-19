#pragma once
#include"Person.h"
#include<iostream>
using namespace std;

class Teacher : public Person{
public:
    Teacher(const string& teacherName) : Person(teacherName){
        cout << "constructing Teacher " << teacherName << endl;
    }
    ~Teacher(){
        cout << "destructing Teacher " << getName() << endl;
    }
};