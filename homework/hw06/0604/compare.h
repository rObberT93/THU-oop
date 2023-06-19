#pragma once
#include <vector>
#include <initializer_list>
#include <functional>
using namespace std;

template <typename T>
class Compare {
private:
    const initializer_list<function<bool(const T&, const T&)>> compare_unit;
    const vector<function<bool(const T&, const T&)>>compare_unit_2;
public:
    Compare(const initializer_list<function<bool(const T&, const T&)>> _compare_unit)
        : compare_unit(_compare_unit) {}
    Compare(const vector<function<bool(const T&, const T&)>> _compare_unit_2)
        : compare_unit_2(_compare_unit_2) {}

    bool operator()(const T& lhs, const T& rhs) const {
        for (const auto& comp : compare_unit) {
            if (comp(lhs, rhs)) {
                return true;
            }
            if (comp(rhs, lhs)) {
                return false;
            }
        }
        return false;
    }
    bool operator()(const vector<int>& lhs, vector<int>& rhs) const {
        for(const auto& comp : compare_unit_2) {
            if(comp(lhs, rhs)) {
                return true;
            }
            if (comp(rhs, lhs)) {
                return false;
            }
        }
        return false;
    }
};
