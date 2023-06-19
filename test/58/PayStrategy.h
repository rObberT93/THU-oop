#pragma once
#include<iostream>
using namespace std;

class PayStrategy {	
public:
    virtual float pay(float money) = 0;
};


class NormalStrategy : public PayStrategy {	
public:
    float pay(float money){
        return money;
    }
};

class RebateStrategy : public PayStrategy {	
public:
    float pay(float money){
        return 0.38 * money;
    }
};

class ReturnStrategy : public PayStrategy {	
public:
    float pay(float money){
        float res = money - (money / 25) * 10;
        return res;
    }
};
