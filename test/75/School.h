#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Student.h"

using namespace std;

class School{
    vector<Student>studentlist;
public:
    int studentNum;

    School(int n) : studentNum(n){ }

    void add_member(const Student& stu){
        studentlist.push_back(stu);
    }

    string operator[](int id) {
        int target = -1;
        for(int i = 0; i < studentNum; i++) {
            if(studentlist[i].number == id){
                target = i;
            }
        }
        if(target == -1) {
            return "Not Found\n";
        }
        else {
            return studentlist[target].get_info();
        }
    }
    
    string operator[](char province)  {
        int target = -1;
        for(int i = 0; i < studentNum; i++) {
            if(studentlist[i].province == province){
                if(target != -1) {
                    if(studentlist[i] > studentlist[target]){
                        target = i;
                    }
                }
                else {
                    target = i;
                }
            }
        }
        if(target == -1) {
            return "Not Found\n";
        }
        else {
            return studentlist[target].get_info();
        }
    }
    
    string operator[](string name){
        int target = -1;
        for(int i = 0; i < studentNum; i++) {
            if(studentlist[i].name == name){
                target = i;
            }
        }
        if(target == -1) {
            return "Not Found\n";
        }
        else {
            return studentlist[target].get_info();
        }
    }
    ~School(){}
};