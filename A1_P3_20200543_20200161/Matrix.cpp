#include "Matrix.h"

template <typename T>
Matrix <T>:: Matrix (int row, int column) {
    nRow_ = row;
    nColumn_ = column;
    matrix_ = new T * [nRow_];
    for (int i = 0; i < nRow_; i++) {
        matrix_ [i] = new T [nColumn_];
    }
}


template <typename T>
Matrix <T>:: Matrix (const Matrix& rhs) {
    nRow_ = rhs.nRow_;
    nColumn_ = rhs.nColumn_;
    matrix_ = new T * [nRow_];
    for (int i = 0; i < nRow_; i++) {
        matrix_ [i] = new T [nColumn_];
    }
    for (int i = 0; i < nRow_; i++) {
        for (int j = 0; j < nColumn_; j++) {
            matrix_ [i][j] = rhs.matrix_[i][j];
        }
    }
}


template <typename T>
Matrix<T> Matrix <T>:: transpose (void) {

    Matrix <T> temp(nColumn_, nRow_);
    for (int i = 0; i < nColumn_; i++) {
        for (int j = 0; j < nRow_; j++) {
            temp.matrix_[i][j] = matrix_ [j][i];
        }
    }
    return temp;
}


template <typename T>
Matrix<T> Matrix <T>:: operator + (const Matrix& rhs) {
    Matrix <T> result (nRow_, nColumn_);
    for (int i = 0; i < nRow_; i++) {
        for (int j = 0; j < nColumn_; j++) {
            result.matrix_[i][j] = matrix_[i][j] + rhs.matrix_[i][j];
        }
    }
    return result;
}



template <typename T>
Matrix<T> Matrix <T>:: operator - (const Matrix& rhs) {
    Matrix <T> result (nRow_, nColumn_);
    for (int i = 0; i < nRow_; i++) {
        for (int j = 0; j < nColumn_; j++) {
            result.matrix_[i][j] = matrix_[i][j] - rhs.matrix_[i][j];
        }
    }
    return result;
}


template <typename T>
Matrix<T> Matrix <T>:: operator * (const Matrix& rhs) {
    Matrix <T> result (nRow_, rhs.nColumn_);
    for (int i = 0; i < nRow_; i++) {
        for (int j = 0; j < rhs.nColumn_; j++) {
            result.matrix_[i][j] = 0;
            for (int k = 0; k < nColumn_; k++) {
                result.matrix_[i][j] += matrix_ [i][k]* rhs.matrix_[k][j];
            }
        }
    }
    return result;
}



template <typename T>
ostream& operator << (ostream& out, const Matrix<T>& rhs) {
    for (int i = 0; i < rhs.nRow_; i++) {
        for (int j = 0; j < rhs.nColumn_; j++) {
            out << rhs.matrix_ [i][j] << '\t';
        }
        out << endl;
    }
    return out;
}

template <typename T>
istream& operator >> (istream& in, Matrix<T> &rhs) {
    for (int i = 0; i < rhs.nRow_; i++) {
        for (int j = 0; j < rhs.nColumn_; j++) {
            in >> rhs.matrix_[i][j];
        }
    }
    return in;
}

template <typename T>
Matrix <T>:: ~Matrix () {
    for (int i = 0; i < nRow_; i++) {
        delete [] matrix_ [i];
    }
    delete matrix_;
}
