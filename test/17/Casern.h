#pragma once
#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include <vector>
#include<iostream>
using namespace std;


class Casern {
    //TODO
    string kindName;
    vector<Footman*>vec_footman;
    vector<Commander*>vec_commander;
    vector<Belong*>vec_belong;

public:
    virtual std::string getKind() = 0;
	//TODO
    virtual void addFootman(Footman* f){
        vec_footman.push_back(f);
    }
    virtual void addCommander(Commander* c){
        vec_commander.push_back(c);
    }
    virtual void addBelong(Belong* b){
        vec_belong.push_back(b);
    }
    virtual Footman* getFootmanbyIndex(int x){
        return vec_footman[x];
    }
    virtual Commander* getCommanderbyIndex(int x){
        return vec_commander[x];
    }
    virtual Belong* getBelongbyIndex(int x){
        return vec_belong[x];
    }
};