#pragma once
#include "LevelStrategy.h"
#include "PerformStrategy.h"
class Calculator{
private:
    LevelStrategy* levelStrategy;
    PerformStrategy* performStrategy;

public:
    Calculator(LevelStrategy* m_levelStrategy, PerformStrategy* m_PerformStrategy) : 
    levelStrategy(m_levelStrategy), performStrategy(m_PerformStrategy){}
    ~Calculator() {}
    int get_base () {
        return levelStrategy->get_base();
    }
    int get_total(int base) {
        int bonus = base + performStrategy->get_bonus(base);
        return bonus;
    }
};