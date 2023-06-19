#pragma once

#include "abstract_compare.h"
#include "point.h"

AbstractCompare<int>* get_compare_int(int type);
AbstractCompare<Point>* get_compare_point(int type);

template<class T>
class CompareInt : public AbstractCompare<int> {
public:
    bool compare(T a, T b);
};

template<class T>
class CompareSum : public AbstractCompare<int> {
public:
    bool compare(T a, T b);
};

template<class T>
class ComparePoint : public AbstractCompare<Point>, public Point {
public:
    friend bool operator<(const Point& p1, const Point& p2);
    bool compare(T p1, T p2);

};

template<class T>
class CompareDistance : public AbstractCompare<Point>, public Point{
public:
    bool compare(T p1, T p2);
};
