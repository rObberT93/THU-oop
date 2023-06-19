//Cow.h
#ifndef COW_H
#define COW_H
#include<string>
#include"Cow.h"
using namespace std;
class Cow {
    public:
        Cow(string name, int lowFeed, int upperFeed, double dailyMilk); // 构造函数 初始化奶牛名字 最小饲料粮 最大饲料粮 每日产奶量
        void produceMilk(); // 一只奶牛一天的产奶
        void eat(int feedCase); // 开始吃 并判断一天吃的够不够
        
        double getMilkProduction() const { return c_milkProduction; } // 返回当日产奶量
        string getCowName() const { return c_name; } // 获取奶牛名字
        int getLow() const{ return c_lowFeed; } // 获取某只奶牛应该吃的下限
        int getUpper() const{ return c_upperFeed; }
        double getDailyMilk() const{ return c_dailyMilk; }
    private:
        string c_name; //奶牛名字
        int c_lowFeed; //最少吃
        int c_upperFeed; //最多吃
        double c_dailyMilk; //一只奶牛每日常规产奶
        double c_milkProduction; //一只奶牛的一天产奶
        int c_currentTotal; //当天全部粮（剩余和补充）
        double milkPerDayPerCow;
};

#endif