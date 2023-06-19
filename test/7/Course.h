#pragma once
#include<iostream>
#include"Student.h"
#include"Teacher.h"
using namespace std;

class Course{
public:
    int stuNum;
    int tempNum = 0;
    const string subName;
    Teacher* teacher;
    Student** student;
    Course(const int& n, const string& s) : stuNum(n), subName(s){
        cout << "constructing Course: " << subName << endl;
        student = new Student*[n];
    };

    void addTeacher(const string& teacherName) {
        teacher = new Teacher(teacherName);
    }

    void addStudent(const string& sname, const int& score, const string& sinfo){
        student[tempNum] = new Student(sname, score, sinfo);
        tempNum ++;
    }

    string getSubject() const{
        return subName;
    }

    Student* getStudent(const string& stuName){
        for(int i = 0; i < stuNum; i++) {
            if(student[i]->getName() == stuName) {
                return student[i];
            }
        }
        return nullptr;
    }

    Teacher* getTeacher(){
        return teacher;
    }

    ~Course(){
        delete teacher;
        for (int i = 0; i < stuNum ; i++)
            delete student[i];
        delete[] student;
        cout << "destructing Course: " << subName << endl;
    }
};