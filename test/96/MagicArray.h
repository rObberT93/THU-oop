#pragma once
#include<iostream>
#include<vector>
#include"Instruction.h"

using namespace std;

class specialElement{
public:
    int id;
    vector<Instruction*>* ins;

    void operator+=(int x){
        ins->push_back(new plusConst(id, x));
    }
    void operator+=(specialElement another) {
        ins->push_back(new plusElement(another.id, id));
    }
    void operator=(specialElement another) {
        ins->push_back(new assignElement(another.id, id));
    }
    friend ostream& operator<<(ostream& out, const specialElement& se){
        se.ins->push_back(new outputElement(out, se.id));
        return out;
    }
};

class MagicArray{
    specialElement* m_array;
    int length;
    vector<Instruction*>instruction_list;

public:
    MagicArray(int n) : length(n){
        m_array = new specialElement[n];
        for(int i = 0; i < n; ++i) {
            m_array[i].id = i;
            m_array[i].ins = &instruction_list;
        }
    }

    void apply(vector<int>& vec) {
        for(auto &i : instruction_list){
            i->apply(vec);
        }
    }

    void apply(vector<double>& vec) {
        for(auto &i : instruction_list){
            i->apply(vec);
        }
    }

    specialElement& operator[](int index){
        return m_array[index];
    }

    vector<Instruction *> &getInstructions(){
        return instruction_list;
    }

    specialElement endl(){
        specialElement k;
        k.id = -1;
        k.ins = &instruction_list;
        return k;
    }
};