#include <iostream>
#include <functional>

// 函数指针类型
typedef bool (*CompFuncPtr)(int, int);

// 函数对象类型
class Greater {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

// 使用 std::function 统一接口的函数
void sortArray(int arr[], int size, std::function<bool(int, int)> comp) {
    // 在此处调用 comp 进行排序逻辑
    // 例如，可以使用 comp(a, b) 来比较元素 a 和 b 的顺序
}

int main() {
    int arr[5] = {5, 2, 3, 4, 1};

    // 使用函数指针
    CompFuncPtr compFunc = [](int a, int b) { return a > b; };
    sortArray(arr, 5, compFunc);

    // 使用函数对象
    Greater greaterObj;
    sortArray(arr, 5, greaterObj);

    // 使用 Lambda 表达式
    sortArray(arr, 5, [](int a, int b) { return a > b; });

    return 0;
}
