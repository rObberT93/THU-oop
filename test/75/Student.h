#pragma once
#include<iostream>
#include<string>

using namespace std;

class Student{
public:
    string name;
    char province;
    int grade;
    string time;
    int number;
    friend istream& operator>>(istream& in, Student& stu);
    
    string get_info() {
        // string date = to_string(time);
        // if(date.length() <= 3){
        //     date = "0" + date;
        // }
        // if(name[0] == '\n'){
        //     name.erase(0, 1);
        // }
        return name+"-"+time+"-"+to_string(grade)+"-"+to_string(number)+"\n";
    }

    bool operator> (const Student& s){
        if(this->time != s.time) return this->time > s.time;
        else {
            return this->number > s.number;
        }
    }
};

istream& operator>>(istream& input, Student& student){
    string data;
    //getchar();
    getline(input, data, '-');
    if(data[0] == '\n'){
        data.erase(0, 1);
    }
    student.name = data;
    getline(input, data, '-');
    student.province = data[0];
    getline(input, data, '-');
    student.grade = stoi(data);
    getline(input, data, '-');
    student.time = data;
    getline(input, data);
    student.number = stoi(data);
    return input;
}