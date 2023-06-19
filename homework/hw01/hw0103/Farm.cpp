//farm.cpp
#include<iostream>
#include<string>
#include "Farm.h"

//Farm.cpp
Farm::Farm(int n) : c_totalProduction(0) {
        cowsArray.reserve(n);
        supplyArray.reserve(n);
}
void Farm::addCow(Cow cow) {
    cowsArray.push_back(cow);
    supplyArray.push_back(0);
}

void Farm::supply(string Cowname,int feed) { // 添加饲料
    for (Cow& cow : cowsArray) {
        if (cow.getCowName() == Cowname) { // 找到指定名字的奶牛
            supplyArray[&cow - &cowsArray[0]] += feed; // 计算奶牛在数组的下标
            break;
        }
    }
}

void Farm::startMeal() { // 开始吃
    for (Cow& cow : cowsArray) {
        int index = &cow - &cowsArray[0];
        if(supplyArray[index] < cow.getLow() && supplyArray[index] > 0) {
            cow.eat(1);
            supplyArray[index] = 0;
        }
        else if(supplyArray[index] == 0) {
            cow.eat(2);
        }
        else if(supplyArray[index] >= cow.getLow() && supplyArray[index] < cow.getUpper()) {
            cow.eat(3);
            supplyArray[index] = 0;
        }
        else {
            cow.eat(4);
            supplyArray[index] -= cow.getUpper();
        }
    }
}

void Farm::produceMilk() { 
    float dailyProduction = 0; // 当日总产量
    for(Cow& cow : cowsArray) {
        cow.produceMilk(); // 获取当日总产量
        dailyProduction += cow.getMilkProduction();
    }
    c_totalProduction += dailyProduction; // 累计总产量
}