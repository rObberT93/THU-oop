#pragma once 
#include<vector>
#include<functional>
using std::vector;

template<typename T>
class MyQueriable {
private:
    vector<T> data;
public:
    MyQueriable() {}
    MyQueriable(const vector<T> & _input) : data(_input){}
    ~MyQueriable() {}

    int size() const{
        return data.size();
    }

    const T& operator[] (int pos) const{
        return data[pos];
    }

    T sum() const{
        T result = T();
        for(auto i : data) {
            result += i;
        }
        return result;
    }

    template<typename FUNC>
    MyQueriable<T> where(FUNC op) {
        vector<T> sub_arr;
        for(auto i : data) {
            if((op)(i)) {
                sub_arr.push_back(i);
            }
        }
        return MyQueriable<T>(sub_arr);
    }

    template<typename FUNC>
    MyQueriable<T> apply(FUNC op) {
        vector<T> sub_arr;
        for(auto i : data) {
            sub_arr.push_back(op(i));
        }
        return MyQueriable<T>(sub_arr);
    }
};

template<typename T>
MyQueriable<T> from(const vector<T> &arr) {
    return MyQueriable<T>(arr); 
}
