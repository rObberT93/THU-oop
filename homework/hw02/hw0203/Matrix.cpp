#include"Matrix.h"
#include<iostream>
//using namespace std;
Matrix::Matrix() : elem(nullptr), col(0), row(0) {}

Matrix::Matrix(int _row, int _col): row(_row), col(_col) {
    elem = new int* [row];
    for(int i = 0; i < row; i++) {
        elem[i] = new int [col];
        for(int j = 0; j < col; j++) {
            elem[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    if(elem != nullptr) {
        for(int i = 0; i < row; i++) {
            delete []elem[i];
        }
        delete[]elem;
    }
}

Matrix Matrix::operator+(const Matrix& old_matrix) {
    Matrix new_matrix(row, col);
    for(int i =0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            new_matrix.elem[i][j] =  old_matrix.elem[i][j] + elem[i][j];
        }
    }
    return new_matrix;
}
Matrix Matrix::operator-(const Matrix& old_matrix) {
    Matrix new_matrix(row, col);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            new_matrix.elem[i][j] = elem[i][j] - old_matrix.elem[i][j];
        }
    }
    return new_matrix;
}

Matrix Matrix::operator*(const int num) {
    Matrix new_matrix(row, col);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            new_matrix.elem[i][j] = elem[i][j] * num;
        }
    }
    return new_matrix;
}

Matrix Matrix::operator*(const Matrix& right_matrix) {
    Matrix new_matrix(row, right_matrix.col);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < right_matrix.col; j++) {
            for(int m = 0; m < col; m++) {
                new_matrix.elem[i][j] += elem[i][m] * right_matrix.elem[m][j]; 
            }
        }
    }
    return new_matrix;
}

int* Matrix::operator[](int i) const {
    return elem[i];
}

Matrix transpose(const Matrix& m) {
    Matrix new_matrix(m.col, m.row);
    for(int i = 0; i < m.row; i++) {
        for(int j = 0; j < m.col; j++) {
            new_matrix.elem[j][i] = m.elem[i][j];
        }
    }
    return new_matrix;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for(int i = 0; i < m.row; i++) {
        for(int j = 0; j < m.col; j++) {
            out << m.elem[i][j] << " ";
        }
        out << std::endl;
    }       
    return out;
}

// std::istream& operator>>(std::istream& in, Matrix& m) {
//     int row, col;
//     in >> row >> col;
//     Matrix temp = Matrix(row, col);
//     for(int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             in >> temp.elem[i][j];
//         }
//     }
//     m.col = col;
//     m.row = row;
//     m = temp;
//     return in;
// }

std::istream& operator>>(std::istream& in, Matrix& m) {
    int row, col;
    in >> row >> col;

    // 如果目标矩阵大小与输入的大小不同，重新分配内存
    if (m.row != row || m.col != col) {
        if (m.elem != nullptr) {
            for (int i = 0; i < m.row; i++) {
                delete[] m.elem[i];
            }
            delete[] m.elem;
        }

        m.row = row;
        m.col = col;
        m.elem = new int*[row];
        for (int i = 0; i < row; i++) {
            m.elem[i] = new int[col];
        }
    }

    // 读取输入数据到目标矩阵中
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            in >> m.elem[i][j];
        }
    }
    return in;
}