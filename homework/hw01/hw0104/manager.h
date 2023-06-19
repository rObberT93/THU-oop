#ifndef MANAGER_H
#define MANAGER_H
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include"chef.h"
using namespace std;
class Manager{
    public:
        void newChef(Chef c);
        void order(string dish, int chefId = -1);
        
    private:
        vector<Chef>chefs; // 所有大厨的姓名和擅长菜名
};

#endif