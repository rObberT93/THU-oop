#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Altset {
    private:
        vector<int>data;
        int len;
        int numOf1;
    public:
        Altset();
        ~Altset();

        Altset(const char *m_data, int m_len);
        Altset& operator = (const Altset &altset); // 拷贝构造函数
        Altset& operator = (Altset &&altset); // 移动构造函数

        void inverse(int index);
        void append(int value);
        bool get(int index) const;
        bool empty() const;
        int count() const;
};
