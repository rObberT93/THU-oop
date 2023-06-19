#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels)
{
    // todo
    vector<function<bool(const vector<int>&, const vector<int>&)>>compare_unit;
    for(const auto& level : sortlevels) {
        function<bool(const vector<int>&, const vector<int>&)> comp;
        if(level.order == ASCEND){
            comp = [level](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[level.column - 1] < rhs[level.column - 1];
            };
        } else {
            comp = [level](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[level.column - 1] > rhs[level.column - 1];           
            };
        }
        compare_unit.push_back(comp);
    }
    return Compare<vector<int>>(compare_unit);
}