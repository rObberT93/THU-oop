#pragma once
#include"Person.h"
#include<iostream>
#include<string>
using namespace std;
class Student : public Person{
public:
    int score;
    Student(const string& _sname, const int& _score, const string& _sinfo) : Person(_sname, _sinfo), score(_score){
        cout << "constructing Student " << getName() << endl;
    }
    ~Student(){
        cout << "destructing Student " << getName() << endl;
    }
    int getScore() const {
        return score;
    }
    string getInfo() const{
        return "Student " + Person::getInfo() + " " + "Score:" + to_string(score);
    }
};