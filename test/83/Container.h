#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class A>
struct info {
    int id;
    int reply;
    A admin;
    bool canVisit = true;
};

template<class A>
class Container {
public:
    vector<info<A>>info_list;
    Container<A>(){}
    void insert(int x, int y, A admin) {
        info<A>obj;
        obj.id = x;
        obj.reply = y;
        obj.admin = admin;
        obj.canVisit = false;
        info_list.push_back(obj);
        //info_list.push_back({x, y, admin, false});
    }
    A* find(int x, int y) {
        for(int i = 0; i < info_list.size(); i++) {
            if(info_list[i].id == x && info_list[i].reply == y){
                return &info_list[i].admin;
            }
        }
        return nullptr;
    }

};