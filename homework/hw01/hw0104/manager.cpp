#include<iostream>
#include"manager.h"
#include"chef.h"
using namespace std;

void Manager::newChef(Chef c) {
    chefs.push_back(c);
}
// order函数 找到厨师类
void Manager::order(string dish, int chefId) {
    if(chefId == -1) { // 未指定厨师
        bool canfind = false;
        for(auto i = 0u; i < chefs.size(); i++) { // 从头遍历
            if(chefs[i].isSignatureDish(dish)) { // 找到擅长菜
                chefs[i].cook(dish); 
                cout << " made an awesome " << dish << endl;
                canfind = true;
                break;  
            }
        }
        if(canfind == false) {
            chefs[0].cook(dish);
            cout << " made a plain " << dish << endl;
        }
    }
    else {
        if(chefs[chefId].isSignatureDish(dish)) {
            chefs[chefId].cook(dish);
            cout << " made an awesome " << dish << endl;
        }
        else {
            chefs[chefId].cook(dish);
            cout << " made a plain " << dish << endl;
        }
    }
}
