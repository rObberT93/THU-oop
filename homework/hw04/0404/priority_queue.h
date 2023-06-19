#pragma once
#include "abstract_compare.h"
#include <vector>
#include <algorithm>

template<class T> class PriorityQueue {
private:
    std::vector<T>que;
    AbstractCompare<T>*cmp;
public:
    PriorityQueue(AbstractCompare<T> *_cmp);
    ~PriorityQueue();
    bool empty();
    int size();
    void push(T element);
    void pop();
    T top();
};