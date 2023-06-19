#include "priority_queue.h"
#include "point.h"
#include "compare.h"
#include <vector>

template<class T>PriorityQueue<T>::PriorityQueue(AbstractCompare<T> *_cmp) : cmp(_cmp) {}

template<class T>PriorityQueue<T>::~PriorityQueue() {
    reverse(que.begin(), que.end());
    while(!que.empty()) {
        std::cout << que.back();
        que.pop_back();
    }
}

template<class T>bool PriorityQueue<T>::empty(){
    if(que.size() == 0) {
        return true;
    }
    return false;
}

template<class T>int PriorityQueue<T>::size() {
    return que.size();
}

template<class T>void PriorityQueue<T>::push(T element) {
    que.push_back(element);
    sort(que.begin(), que.end(), [this](T a, T b){
        return this->cmp->compare(a, b);
    });
}

template<class T>void PriorityQueue<T>::pop() {
    reverse(que.begin(), que.end());
    que.pop_back();
    reverse(que.begin(), que.end());
}

template<class T> T PriorityQueue<T>::top() {
    return que.front();
}

template class PriorityQueue<int>;
template class PriorityQueue<Point>;