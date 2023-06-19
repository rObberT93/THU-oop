#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Instruction
{
public:
    virtual void apply(vector<int> &vec) = 0;
    virtual void apply(vector<double> &vec) = 0;
    virtual void output() = 0;
};

class plusConst : public Instruction{
    int pos;
    int num;

public:
    plusConst(int p, int x) : pos(p), num(x){};
    void apply(vector<int> &vec) {
        vec[pos] += num;
    }
    void apply(vector<double> &vec){
        vec[pos] += num;
    }
    void output() {
        cout << "arr[" << pos << "]" << " += " << num << endl;
    }
};

class plusElement : public Instruction{
    int pos1;
    int pos2;

public:
    plusElement(int p1, int p2) : pos1(p1), pos2(p2){};
    void apply(vector<int> &vec) {
        vec[pos2] += vec[pos1];
    }
    void apply(vector<double> &vec){
        vec[pos2] += vec[pos1];
    }
    void output() {
        cout << "arr[" << pos2 << "]" << " += " << "arr[" << pos1 << "]" << endl;
    }
};

class assignElement : public Instruction{
    int pos1;
    int pos2;

public:
    assignElement(int p1, int p2) : pos1(p1), pos2(p2){};
    void apply(vector<int> &vec) {
        vec[pos2] = vec[pos1];
    }
    void apply(vector<double> &vec){
        vec[pos2] = vec[pos1];
    }
    void output() {
        cout << "arr[" << pos2 << "]" << " = " << "arr[" << pos1 << "]" << endl;
    }
};

class outputElement : public Instruction{
    int pos;
    ostream& out;
public:
    outputElement(ostream& _out, int _pos) : out(_out), pos(_pos){};
    void apply(vector<int> &vec) {
        if(pos != -1) {
            out << vec[pos];
            return;
        }
        out << endl;
    }
    void apply(vector<double> &vec){
        if(pos != -1) {
            out << vec[pos];
            return;
        }
        out << endl;
    }
    void output() {
        if(pos != -1) {
            cout << "cout << arr[" << pos <<"]" << endl;
            return;
        }
        cout << "cout << endl" << endl;
    }      
};