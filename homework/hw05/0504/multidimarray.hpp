#pragma once
#include <iostream>
#include <vector>
#include <memory>
using std::vector;

template <typename T, int k>
class MultiDimArray {
private:
    vector<MultiDimArray<T, k - 1> > data;
public:
    MultiDimArray() {}
    MultiDimArray(const vector<int>& _init) {
        vector<int>temp(_init.size() - 1);
        for(int i = 1; i < k; i++) {
            temp[i - 1] = _init[i];
        }
        data.resize(_init[0],  MultiDimArray<T, k - 1>(temp));
    }

    ~MultiDimArray() {}

    MultiDimArray(const MultiDimArray<T, k>& other) { // 拷贝构造
        data = other.data;
    }

    MultiDimArray(MultiDimArray<T, k>&& other) { // 移动构造
        data = std::move(other.data);
    }

    MultiDimArray<T, k>& operator=(const MultiDimArray<T, k>& other) { // 拷贝赋值
        if(this != &other) {
            data = other.data;
        }
        return *this;
    }

    MultiDimArray<T, k>& operator=(MultiDimArray<T, k>&& other) { // 移动赋值
        if(this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }

    MultiDimArray<T, k-1>& operator[](const int pos) {
        return data[pos];
    }
};

template <typename T> 
class MultiDimArray<T, 1> {
private:
    vector<T>data;
public:
    MultiDimArray(const vector<int>& _init) {
        data.resize(_init[0]);
    }

    T& operator[](const int pos) {
        return data[pos];
    }
};