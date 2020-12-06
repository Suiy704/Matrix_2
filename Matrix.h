#include <string>
#include <iostream>

#ifndef PROJECT1_MULTIPLY_H
#define PROJECT1_MULTIPLY_H
using namespace std;

class Matrix {
private:
    int row;
    int column;
    float *data;
    int *count = 0;

public:
    Matrix();

    Matrix(int r, int c, float *da = NULL);

    Matrix(const Matrix &m);

    ~Matrix();

    Matrix operator*(const Matrix &m) const;

    friend Matrix operator*(float f, Matrix &m);

    friend Matrix operator*(Matrix &m, float f);

    Matrix operator+(const Matrix &m) const;

    Matrix operator-(const Matrix &m) const;

    Matrix &operator=(const Matrix &m);

    friend ostream &operator<<(ostream &os, const Matrix &m);

    bool operator==(const Matrix &m) const;

    bool operator!=(const Matrix &m) const;

    Matrix trans(Matrix &m);

    Matrix getcom_ab(Matrix &m, int a, int b);
};

bool judge(string temp);

Matrix input(int r, int c);


#endif //PROJECT1_MULTIPLY_H
