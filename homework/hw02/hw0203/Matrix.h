#ifndef __MATRIX__H__
#define __MATRIX__H__
#include<iostream>
class Matrix {
private:
    int** elem;
    int col, row;
    
public:
    Matrix();
    Matrix(int _row, int _col);
    ~Matrix();

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const int); // 数乘
    Matrix operator*(const Matrix&); // 左乘
    friend Matrix transpose(const Matrix&);
    int* operator[](int) const;
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
};
#endif