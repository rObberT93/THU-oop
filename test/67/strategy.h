#pragma once
#include "message.h"
#include <vector>
#include <algorithm>
using namespace std;

class Strategy {	
public:
    vector<Message> stu_list;
    virtual void sort(vector<Message>& stu_list) = 0;
    virtual bool cmp(Message& s1, Message& s2) = 0;
    virtual ~Strategy(){}
};

class FirstStrategy : public Strategy {	
public:
    bool cmp(Message& s1, Message& s2) {
        if(s1.first_score() != s2.first_score())
            return s1.first_score() > s2.first_score();
        else 
            return s1.id() > s2.id();
    }
    void sort(vector<Message>& stu_list){
        std::sort(stu_list.begin(), stu_list.end(), 
            [this](Message& s1, Message& s2){
                return cmp(s1, s2);
            });
    }
};

class SecondStrategy : public Strategy {	
public:
    bool cmp(Message& s1, Message& s2) {
        if(s1.second_score() != s2.second_score())
            return s1.second_score() > s2.second_score();
        return s1.id() > s2.id();
    }
    void sort(vector<Message>& stu_list){
        std::sort(stu_list.begin(), stu_list.end(), 
            [this](Message& s1, Message& s2){
                return cmp(s1, s2);
            });
    }
};

class TotalStrategy : public Strategy {	
public:
    bool cmp(Message& s1, Message& s2) {
        if(s1.total_score() != s2.total_score())
            return s1.total_score() > s2.total_score();
        return s1.id() > s2.id();
    }
    void sort(vector<Message>& stu_list){
        std::sort(stu_list.begin(), stu_list.end(), 
            [this](Message& s1, Message& s2){
                return cmp(s1, s2);
            });
    }
};

class StudentidStrategy : public Strategy {	
public:
    bool cmp(Message& s1, Message& s2) {
        return s1.id() > s2.id();
    }
    void sort(vector<Message>& stu_list){
        std::sort(stu_list.begin(), stu_list.end(), 
            [this](Message& s1, Message& s2){
                return cmp(s1, s2);
            });
    }
};