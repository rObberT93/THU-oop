#include "Rack.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

Rack::Rack() {
    goods.clear();
    size = 0;
}
Rack::Rack(const Rack &r) {
    size = r.size;
    goods.clear();
    goods = r.goods;
}

Rack::~Rack() {
    goods.clear();
    size = 0;
}

bool operator< (const Rack &left, const Rack &right) {
   return left.size < right.size;
}

bool operator> (const Rack &left, const Rack &right) {
   return left.size > right.size;
}

bool operator== (const Rack &left, const Rack &right) {
   return left.size == right.size;
}

Rack& Rack::operator+= (int number) {
    this->goods.push_back(number);
    size ++;
    return *this;
}

Rack& Rack::operator+= (const Rack& r) {
    for(int i = 0; i < r.size; i++) {
        this->goods.push_back(r.goods[i]);
    }
    this->size = this->goods.size();
    return *this;
}

std::ostream& operator<<(std::ostream&out, const Rack &r) {
    for(int item : r.goods) {
        out <<" " << item;
    }
    return out;
}


Rack& operator, (const int &aGoods, const Rack& shelf) {
    Rack *tmp = new Rack();
    tmp->goods.push_back(aGoods);
    for(int i : shelf.goods) {
        tmp->goods.push_back(i);
    }
    tmp->size = tmp->goods.size();
    return *tmp;
}
Rack& operator, (const Rack& shelf1, const Rack& shelf2) {
    Rack *tmp = new Rack();
    for(int i : shelf1.goods) {
        tmp->goods.push_back(i);
    }
    for(int i : shelf2.goods) {
        tmp->goods.push_back(i);
    }
    tmp->size = tmp->goods.size();
    return *tmp;
}
Rack& operator, (const Rack& shelf, const int &aGoods) {
    Rack *tmp = new Rack();
    for(int i : shelf.goods) {
        tmp->goods.push_back(i);
    }
    tmp->goods.push_back(aGoods);
    tmp->size = tmp->goods.size();
    return *tmp;
}

Rack& Rack::operator&(const Rack &r) {
    Rack *tmp = new Rack();
    std::unordered_set<int> set(r.goods.begin(), r.goods.end());
    for(int i : this->goods) {
        if(set.count(i) == 1 && find(tmp->goods.begin(), tmp->goods.end(), i) == tmp->goods.end()) {
            tmp->goods.push_back(i);
        } 
    }
    tmp->size = tmp->goods.size();
    return *tmp;
}

int Rack::operator()(const int &i) {
    int res = 0;
    for(int j : this->goods) {
        if(j == i) res++;
    }
    return res;
}

Rack& Rack::operator~() {
    std::reverse(this->goods.begin(), this->goods.end());
    return *this;
}

Rack& Rack::operator--(int) { // 最后
    this->goods.pop_back();
    this->size --;
    return *this;
}

Rack& Rack::operator--() { // 最前
    this->goods.erase(this->goods.begin());
    this->size --;
    return *this;
}