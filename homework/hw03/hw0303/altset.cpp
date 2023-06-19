#include "altset.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

Altset::Altset() {
    data.clear();
    len = 0;
    numOf1 = 0; 
}
Altset::Altset(const char *m_data, int m_len): len(m_len){
    for(int i = 0; i < len; i++) {
        data.push_back(m_data[i] - '0');
        if(data[i] == 1) numOf1 ++;
    }
    reverse(data.begin(), data.end()); 
}
Altset::~Altset() {
    data.clear();
}
Altset& Altset::operator = (const Altset &altset){
    if(this == &altset) return *this;
    data.clear();
    data = altset.data;
    len = altset.len;
    numOf1 = altset.numOf1;
    return *this;
}
Altset& Altset::operator = (Altset &&altset){
    if(this == &altset) return *this;
    data.clear();
    data = move(altset.data);
    altset.data.clear();
    len = altset.len;
    numOf1 = altset.numOf1;
    altset.len = 0;
    altset.numOf1 = 0;
    return *this;
}

void Altset::inverse(int index){
    if(data[index] == 1) {
        data[index] = 0;
        numOf1 --;
    }
    else {
        data[index] = 1;
        numOf1 ++;
    }
}

void Altset::append(int value){
    len++;
    if(value == 1) numOf1 ++;
    data.push_back(value);
}

bool Altset::get(int index) const{
    if(data[index] == 1) 
        return true;
    return false;
}
bool Altset::empty() const{
    return data.empty();
}
int Altset::count() const{
    return numOf1;
}