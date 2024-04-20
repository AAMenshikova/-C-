#include <cmath>
#include "head.h"

void func1_1(int &a, int &b) {
    if (a < b) {
        b = b % a;
    } else {
        a = a % b;
    }
}

void func1_2(int *a, int *b) {
    if (*a < *b) {
        *b = *b % *a;
    } else {
        *a = *a % *b;
    }
}

void func2_1(double &x) {
    x = round(x);
}

void func2_2(double *x) {
    *x = round(*x);
}

void func3_1(int &r, int &d) {
    r = r - d;
}

void func3_2(int *r, int *d) {
    *r = *r - *d;
}

void func4_1(int (&x)[3][3]) {
    std::swap(x[0][1], x[1][0]);
    std::swap(x[0][2], x[2][0]);
    std::swap(x[1][2], x[2][1]);
}

void func4_2(int (*y)[3][3]) {
    std::swap((*y)[0][1], (*y)[1][0]);
    std::swap((*y)[0][2], (*y)[2][0]);
    std::swap((*y)[1][2], (*y)[2][1]);
}