#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>

template <typename T>
class Matrix {
private:
    T **matrix_;
    int nRow_ = 0;
    int nColumn_ = 0;
public:
    Matrix (int, int);
    Matrix (const Matrix&);
    Matrix transpose (void);
    Matrix operator + (const Matrix&);
    Matrix operator - (const Matrix&);
    Matrix operator * (const Matrix&);
    friend std::istream& operator >> (std::istream&, Matrix&);
    friend std::ostream& operator << (std::ostream&,const Matrix&);
    ~Matrix ();
};

#endif // MATRIX_H_INCLUDED
