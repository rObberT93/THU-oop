//Farm.h
#ifndef FARM_H
#define FARM_H
#include<vector>
#include<string>
#include "Cow.h"
using namespace std;
class Farm {
    public:
        Farm(int n); // 构造函数 ： 奶牛数 每头奶牛的信息

        void addCow(Cow); // 添加奶牛
        void startMeal(); // 开始喂食所有奶牛
        void supply(string name, int feed); // 给指定的奶牛添加饲料
        void produceMilk(); // 收取所有奶牛一天的产奶量 并计算总产奶量

        float getMilkProduction() const {return c_totalProduction;} // 返回当前养殖场的总产奶量
        
    private:
        vector<Cow>cowsArray; // 奶牛数组 ： 包含奶牛全部信息
        vector<int>supplyArray; // 奶牛饲料数组
        float c_totalProduction; // 累计总产量
};

#endif