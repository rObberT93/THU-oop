#include <iostream>
#include <functional>

void function1() {
    std::cout << "Function 1" << std::endl;
}

class Functor {
public:
    void operator()() {
        std::cout << "Functor" << std::endl;
    }
};

int main() {
    std::function<void()> func1 = function1;
    std::function<void()> func2 = Functor();

    func1();  // 调用函数指针
    func2();  // 调用函数对象

    return 0;
}
