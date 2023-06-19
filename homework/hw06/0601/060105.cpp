#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
// bool comp(int a, int b) { return a > b; }

// void my_sort(vector<int>& arr) {
//     // sort(arr.begin(), arr.end(), greater<int>());
//     sort(arr.begin(), arr.end(), comp);
// }
// template<class T>
// class Greater {
// public:
//     bool operator()(T& a, T& b) const { return a > b; }
// };

// void my_sort(vector<int>& arr) {
//     sort(arr.begin(), arr.end(), Greater<int>());
// }
class IntNum {
public:
    int value;
    IntNum(int _value) : value(_value) {}
    bool operator<(const IntNum& b) const { 
        return value > b.value;
    };
};

void my_sort(vector<int>& arr) {
    vector<IntNum> nums;
    for (int i : arr) nums.push_back(IntNum(i));
    sort(nums.begin(), nums.end());
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = nums[i].value;
    }
}


int main() {
    vector<int>arr = {2, 3, 1, 4};
    my_sort(arr);
    for(auto i : arr) {
        cout << i;
    }
}