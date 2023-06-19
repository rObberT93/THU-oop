#pragma once
class PerformStrategy {
private:
    double perform;
public:
    PerformStrategy() {};
    PerformStrategy(double pre) : perform(pre){};
    virtual int get_bonus(int base) = 0; 
};

class sPerformStrategy : public PerformStrategy{
private:
    double perform;
public:
    sPerformStrategy(double pre) : perform(pre){}
    int get_bonus(int base) override{
        return 1000;
    }
};

class mPerformStrategy : public PerformStrategy{
private:
    double perform;
public:
    mPerformStrategy(double pre) : perform(pre){}
    int get_bonus(int base) override{
        return static_cast<int>(base * perform);
    }
};

class lPerformStrategy : public PerformStrategy{
private:
    double perform;
public:
    lPerformStrategy(double pre) : perform(pre){}
    int get_bonus(int base) override{
        return static_cast<int>(2 * base * perform);
    }
};