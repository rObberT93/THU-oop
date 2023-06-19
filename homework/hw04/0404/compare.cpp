#include "compare.h"

template<class T>
bool CompareInt<T>::compare(T a, T b){
    return a < b; 
}

template<class T>
bool CompareSum<T>::compare(T a, T b) {
    int sum1 = 0, sum2 = 0, t = a;
    while(t) {
        sum1 += t % 10;
        t /= 10;
    }
    t = b;
    while(t) {
        sum2 += t % 10;
        t /= 10;
    }
    if(sum1 != sum2) return sum1 < sum2;
    return a < b;
}

bool operator<(const Point& p1, const Point& p2) {
    if(p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
};

template<class T>
bool ComparePoint<T>::compare(T p1, T p2) {
    return p1 < p2;
}

template<class T>
bool CompareDistance<T>::compare(T p1, T p2) {
    int dis1 = p1.x * p1.x + p1.y * p1.y;
    int dis2 = p2.x * p2.x + p2.y * p2.y;
    if(dis1 != dis2) {
        return dis1 < dis2;
    }
    return p1 < p2;
}


AbstractCompare<int>* get_compare_int(int type) {
    if(type == 1) {
        return new CompareInt<int>() ;
    }
    else {
        return new CompareSum<int>();
    }
}

AbstractCompare<Point>* get_compare_point(int type) {
    if(type == 3) {
        return new ComparePoint<Point>();
    }
    else {
        return new CompareDistance<Point>();
    }
}
