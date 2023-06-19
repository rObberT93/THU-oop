//Cow.cpp
#include<iostream>
#include<string>
#include "Cow.h"
using namespace std;
Cow::Cow(string name, int lowFeed, int upperFeed, double dailyMilk)
    : c_name(name), c_lowFeed(lowFeed), c_upperFeed(upperFeed),c_dailyMilk(dailyMilk)
    {}

void Cow::eat(int feedCase) {
    // 计算某只奶牛在某一天的产奶量
    if(feedCase == 1) { // 吃不够 当日减半
        milkPerDayPerCow = c_dailyMilk / 2;
    }
    else if(feedCase == 2) { // 没有粮食可以吃
        milkPerDayPerCow = 0;
    }
    else if(feedCase == 3){ // 吃够最低限度的粮食，但没有到最大限度
        milkPerDayPerCow = c_dailyMilk;
    }
    else if(feedCase == 4) {
        milkPerDayPerCow = c_dailyMilk;
    }
}

void Cow::produceMilk() {
    c_milkProduction = milkPerDayPerCow;
}