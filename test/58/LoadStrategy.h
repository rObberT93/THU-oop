#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

class LoadStrategy {
public:
    virtual float operate() = 0;
};

class NumberLoadStrategy : public LoadStrategy {
public:
    float operate(){
        float pay;
        cin >> pay;
        return pay;
    }
};

class WordLoadStrategy : public LoadStrategy {
public:
    float operate(){
        map <string, int> word_to_num = {
            make_pair("zero", 0),
            make_pair("one", 1),
            make_pair("two", 2),
            make_pair("three", 3),
            make_pair("four", 4),
            make_pair("five", 5),
            make_pair("six", 6),
            make_pair("seven", 7),
            make_pair("eight", 8),
            make_pair("nine", 9)
        };
        string temp;
        int total = 0;
        vector<int> money_list;
        while(temp != "#") {
            cin >> temp;
            money_list.push_back(word_to_num[temp]);
        }
        int len = money_list.size();
        for(int i = 0; i < len - 1 ; i ++){
            total += pow(10, len - 2 - i) * money_list[i];
        }
        return total;
    }
};
