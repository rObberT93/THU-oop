//main.cpp
#include <iostream>
#include <string>
#include "Cow.h"
#include "Farm.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    Farm farm(n); // 构造函数 ： 奶牛数
    string name; // 奶牛名
    int l, u, m; // low upper milk
    for(int i = 0; i < n; ++i){ // 添加奶牛
        cin >> name >> l >> u >> m;
        Cow cow(name, l, u, m);
        farm.addCow(cow);
    }

    int k; // 天数
    cin >> k;
    int t; // 给几只奶牛补充饲料
    int a; // 给某只奶牛补充多少饲料
    for(int i = 0; i < k; ++i){
        cin >> t; 
        for(int j = 0; j < t; ++j){
            cin >> name >> a; // 输入补充饲料的奶牛名 和 补充饲料的量
            farm.supply(name, a); // 调用补充函数
        }
        farm.startMeal(); // 开始喂食
        farm.produceMilk(); // 收取当天所有奶牛的产奶量
    }
    printf("%.1f", farm.getMilkProduction());
    //system("pause");
    return 0;
}