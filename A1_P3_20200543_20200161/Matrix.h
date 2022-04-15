#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

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

    template <typename T2>
    friend istream& operator >> (istream& in, Matrix<T2>& rhs);

    template <typename T2>
    friend ostream& operator << (ostream& out, const Matrix<T2>& rhs);

    ~Matrix ();
};


#endif // MATRIX_H
