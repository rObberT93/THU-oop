#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"
using namespace std;

class Calculator {								
public:
    LoadStrategy* loadStrategy;
    PayStrategy* payStrategy;
    Calculator(LoadStrategy* m_load, PayStrategy* m_pay): loadStrategy(m_load),  payStrategy(m_pay){};
    float load(){
        return loadStrategy->operate();
    }
    float pay(float money) {
        return payStrategy->pay(money);
    }
};