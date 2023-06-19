#pragma once
#include<iostream>
#include<vector>

class Rack {
    private:
        std::vector<int>goods;
        int size;
    public:
        Rack(); //  构造函数
        Rack(const Rack&); // 复制构造
        ~Rack(); // 析构
        Rack& operator+= (int number);
        Rack& operator+= (const Rack &r);
        friend bool operator< (const Rack &left, const Rack &right);
        friend bool operator> (const Rack &left, const Rack &right);
        friend bool operator== (const Rack &left, const Rack &right);
        friend Rack& operator, (const int &aGoods, const Rack& shelf); 
        friend Rack& operator, (const Rack& shelf1, const Rack& shelf2); 
        friend Rack& operator, (const Rack& shelf, const int &aGoods); 
        Rack& operator-- (int); // 删掉最后
        Rack& operator-- (); // 删掉最前
        Rack& operator~ (); // 倒序
        int operator()(const int &i); //返回标号为i的个数
        Rack& operator& (const Rack &r); // 相同的
        friend std::ostream& operator<<(std::ostream&out, const Rack &r);

};