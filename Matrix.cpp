#include "Matrix.h"
#include <iostream>
#include <string.h>

using namespace std;

Matrix::Matrix() {
    row = 1;
    column = 1;
    data = new float[1];
    data = 0;
    count = new int;
    (*count) = 1;
//    cout << (*count) << "   The matrix I = 1 has been generated." << endl;
}

Matrix::Matrix(int r, int c, float *da) {
    row = r;
    column = c;
    data = new float[row * column]();
    if (da != NULL) {
        for (int i = 0; i < row * column; ++i) {
            *(data + i) = *(da + i);
        }
    }
    count = new int;
    (*count) = 1;
//    cout << (*count) << "   Matrix has been construct with 3 parameters." << endl;
}

Matrix::Matrix(const Matrix &m) {
    row = m.row;
    column = m.column;
    (*m.count) += 1;
    data = m.data;
    count = m.count;
//    cout << (*count) << "   Copy constructor." << endl;
}

Matrix::~Matrix() {
//    cout << *count << endl;
    if (*(count) == 1) {
        delete[] data;
        delete count;
//        cout << "data has been deleted." << endl;
    } else {
        (*count)--;
//        cout << "count has been minus 1." << endl;
    }
}

Matrix Matrix::operator*(const Matrix &m) const {
    if (column == m.row) {
        float *result = new float[row * m.column]();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < m.column; ++j) {
                for (int k = 0; k < column; ++k) {
                    *(result + i * m.column + j) =
                            *(result + i * m.column + j) + (*(data + i * column + k) * *(m.data + j + k * m.column));
                }
            }
        }
        Matrix results(row, m.column, result);
        cout << results;
        return results;
    } else {
        cout << "These two matrices cannot be multiplied." << endl << endl;
        Matrix results(-1, -1, 0);
        return results;
    }
}

Matrix Matrix::operator+(const Matrix &m) const {
    if (row == m.row && column == m.column) {
        Matrix results(row, m.column);
        //   float *result = new float[row * m.column]();
        for (int i = 0; i < row * column; ++i) {
            *(results.data + i) = *(data + i) + *(m.data + i);
        }
        cout << results;
        return results;
    } else {
        cout << "These two matrices cannot be added." << endl << endl;
        Matrix results(-1, -1, 0);
        return results;
    }

}

Matrix Matrix::operator-(const Matrix &m) const {
    if (row == m.row && column == m.column) {
        float *result = new float[row * m.column]();
        for (int i = 0; i < row * column; ++i) {
            *(result + i) = *(data + i) - *(m.data + i);
//                cout << *(result+i) << endl;

        }
        Matrix results(row, column, result);
        cout << results;
        return results;
    } else {
        Matrix results(-1, -1, 0);
        cout << "These two matrices cannot be subtracted." << endl << endl;
        return results;
    }
}

Matrix operator*(float f, Matrix &m) {
    float *result = new float[m.row * m.column]();
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            *(result + i * m.column + j) = f * *(m.data + i * m.column + j);
//            cout << *(result+i*m.column+j) << endl;
        }
    }
    Matrix results(m.row, m.column, result);
    cout << results;
    return results;
}

Matrix operator*(Matrix &m, float f) {
    float *result = new float[m.row * m.column]();
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            *(result + i * m.column + j) = f * *(m.data + i * m.column + j);
//            cout << *(result+i*m.column+j) << endl;
        }
    }
    Matrix results(m.row, m.column, result);
    cout << results;
    return results;
}

Matrix &Matrix::operator=(const Matrix &m) {
    if (this == &m) {
        return *this;
    }
    if (*(count) == 1) {
        delete count;
        delete[] data;
    } else {
        *(count)--;
    }

    count = m.count;
    row = m.row;
    column = m.column;
    *(count)++;
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &m) {
    cout.setf(ios_base::floatfield, ios_base::fixed);
    cout.precision(2);
    if (m.row != -1) {
        for (int i = 0; i < m.row; ++i) {
            for (int j = 0; j < m.column; ++j) {
                os << *(m.data + i * m.column + j) << " ";
            }
            os << endl;
        }
    }
    os << endl;
}

bool Matrix::operator==(const Matrix &m) const {
    if (row == m.row && column == m.column) {
        bool b = true;
        for (int i = 0; i < row * column; ++i) {
            if (*(data + i) != *(m.data + i)) {
                b = false;
                break;
            }
        }
        return b;
    } else {
        return false;
    }
}

bool Matrix::operator!=(const Matrix &m) const {
    bool b = true;
    if (row != m.row || column != m.column) {
        b = false;
    } else {
        for (int i = 0; i < row * column; ++i) {
            if (*(data + i) != *(m.data + i)) {
                b = false;
                break;
            }
        }
    }
    return b;
}

bool judge(string temp) {
    int sigNum = 0;
    int pointNum = 0;
    int eNum = 0;
    string data = (temp[0] == '-' ? temp.substr(1) : temp);

    for (int i = 0; i < data.size(); ++i) {
        if (!isdigit(data[i]) && data[i] != '-' && data[i] != '+' && data[i] != '.' && data[i] != 'E' &&
            data[i] != 'e') {
            return false;
        } else if (data[i] == '+' || data[i] == '-') {
            if (sigNum > 0) {
                return false;
            } else if (i == 0 || data[i - 1] != 'E' || data[i - 1] != 'e') {
                return false;
            } else {
                sigNum++;
            }
        } else if (data[i] == '.') {
            if (pointNum > 0) {
                return false;
            } else if (i == data.size() - 1) {
                return false;
            } else {
                pointNum++;
            }
        } else if (data[i] == 'E' || data[i] == 'e') {
            if (eNum > 0) {
                return false;
            } else if (i == data.size() - 1) {
                return false;
            } else {
                eNum++;
            }
        }
    }
    return true;
}

Matrix input(int r, int c) {
    float *data = new float[r * c]();
    cout << "Please input your matrix:" << endl;
    string temp;
    for (int i = 0; i < r * c; ++i) {
        cin >> temp;
        if (judge(temp)) {
            data[i] = stof(temp);
        } else {
            cout << "This input is illegal.";
            exit(0);
        }
    }
    Matrix m(r, c, data);
    return m;
}
Matrix Matrix::trans(Matrix& m){
    for(int i=0;i<m.row;i++){
        for(int j=i+1;j<m.column;j++){
            float temp = *(m.data+i*m.row+j);
            *(m.data+i*m.row+j) = *(m.data+j*m.row+i);
            *(m.data+j*m.row+i) = temp;
        }
    }
    return m;
}
Matrix Matrix::getcom_ab(Matrix &m,int a,int b) {
    float nf[(m.row-1)*(m.column-1)];
    int x=0;
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            if (i!=a){
                int check=b+i*m.column;
                if (i*m.column+j!=check){
                    nf[x]=data[i*m.column+j];
                    x++;
                }
            }
        }
    }
    Matrix nm(row-1,column-1,nf);
    return nm;
}
