#include <iostream>
#include <string>
#include "chef.h"
#include "manager.h"

int main() {
    int C, N;
    Manager manager;

    std::cin >> C; // chef的数量
    for (int i = 0; i < C; ++i) {
        std::string name, signatureDish;
        std::cin >> name >> signatureDish; // 大厨的名字和擅长的菜品名称
        manager.newChef(Chef(name, signatureDish));
    }

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int t, chefId;
        std::string dish;
        std::cin >> t >> dish;
        if (t == 0) {
            manager.order(dish);
        }
        else {
            std::cin >> chefId;
            manager.order(dish, chefId);
        }
    }
    system("pause");
    return 0;
}