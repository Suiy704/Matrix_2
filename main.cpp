#include <iostream>
#include <chrono>
#include "Matrix.h"
//#include <Cblas.h>

using namespace std;

#define TIME_START start=std::chrono::steady_clock::now();
#define TIME_END(NAME) end= std::chrono::steady_clock::now();\
        duration= std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();\
        cout << (NAME) << ", duration=" << duration <<"ms"<<endl;


int main() {
    float data1[10] = {1.1, 3.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    float data2[10] = {1.1, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    cout << "Print 1 for custom matrix, 2 for default matrix, 3 for time comparison or 4 for transposing and taking the submatrix:" << endl;
    int a = 0;
    cin >> a;
    if (a == 1) {
        Matrix m1(2, 5, data1);
        Matrix m2(5, 2, data1);
        Matrix m3(2, 5, data2);
        cout << "The result of addition is:" << endl;
        Matrix madd1 = m1 + m3;
        cout << "The result of bad_addition is:" << endl;
        Matrix bad_madd = m1 + m2;
        cout << "The result of subtraction is:" << endl;
        Matrix msub1 = m1 - m3;
        cout << "The result of bad_subtraction is:" << endl;
        Matrix bad_msub = m1 - m2;
        cout << "The result of multiplication is:" << endl;
        Matrix mmmul1 = m1 * m2;
        cout << "The result of bad_multiplication is:" << endl;
        Matrix bad_mmmul = m1 * m3;
        cout << "The result of scalar multiplication 1 is:" << endl;
        Matrix mumul1 = 3.1 * m1;
        cout << "The result of scalar multiplication 2 is:" << endl;
        Matrix mumul2 = m1 * 3.1;
    }
    else if (a == 2) {
        int row1, column1, row2, column2;
        cout << "Please enter the number of rows of the first matrix:";
        cin >> row1;
        cout << "Please enter the number of columns of the first matrix:";
        cin >> column1;
        cout << "Please enter the number of rows of the second matrix:";
        cin >> row2;
        cout << "Please enter the number of columns of the second matrix:";
        cin >> column2;
        Matrix m1 = input(row1, column1);
        Matrix m2 = input(row2, column2);
        cout << "The result of addition is:" << endl;
        Matrix madd2 = m1 + m2;
        cout << "The result of subtraction is:" << endl;
        Matrix msub2 = m1 - m2;
        cout << "The result of multiplication is:" << endl;
        Matrix mmul2 = m1 * m2;
        cout << "The result of scalar multiplication is:" << endl;
        Matrix mnmul2 = 1.6 * m1;
    }
    else if (a == 3) {
        float *data = new float[1000000]();
        data[0] = 1.0f;
        data[1] = 2.0f;
        Matrix m(1000, 1000, data);

        auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        auto duration = 0L;
        TIME_START
        Matrix add = m + m;
        TIME_END("Addition")
        TIME_START
        Matrix mul = m * m;
        TIME_END("Multiplication")
    }
    else if (a==4){
        float f[9]={1,2,3,4,5,6,7,8,9};
        Matrix m(3,3,f);
        Matrix nm=m.getcom_ab(m,1,1);
        cout << "begin matrix m:" << endl << m ;
        cout << "The submatrix of row 2, column 2 nm:" << endl<<nm;
        Matrix tm=m.trans(m);
        cout << "The transpose of m is:" << endl;
        cout << tm;
    }
    else {
        cout << "This is not an legal input!" << endl;
    }
    return 0;
}
