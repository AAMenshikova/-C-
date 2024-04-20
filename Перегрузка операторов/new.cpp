#include "head.h"
#include <iostream>
#include <math.h>

using namespace std;

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::Complex(const Complex &c) {
    this->real = c.real;
    this->imaginary = c.imaginary;
}

Complex Complex::operator&(const double &c) {
    return Complex(real * c, imaginary * c);
}

Complex Complex::operator+(const Complex &complex2) {
    return Complex(real + complex2.real, imaginary + complex2.imaginary);
}

Complex Complex::operator*(const Complex &complex2) {
    return Complex(real * complex2.real - imaginary * complex2.imaginary,
                   real * complex2.imaginary + imaginary * complex2.real);
}

double Complex::operator=(const Complex &complex1) {
    return sqrt(complex1.real * complex1.real + complex1.imaginary * complex1.imaginary);
}

void Complex::print(Complex complex) {
    cout << complex.real << " + " << complex.imaginary << 'i';
}

Subset::Subset(Subset &subset1) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        subset1.A[x] = true;
    }
}

vector<bool> Subset::operator+(const Subset &subset2) {
    vector<bool> set1(10, false);
    for (int i = 0; i < 10; i++) {
        if (A[i] or subset2.A[i]) {
            set1[i] = true;
        }
    }
    return set1;
}

bool Subset::operator==(const Subset &subset2) {
    bool flag = true;
    while (flag) {
        for (int i = 0; i < 10; i++) {
            if (A[i] != subset2.A[i]) {
                flag = false;
            }
        }
    }
    return flag;
}

bool Subset::operator!=(const Subset &subset) {
    bool flag = true;
    while (flag) {
        for (int i = 0; i < 10; i++) {
            if (A[i] != subset.A[i]) {
                flag = false;
            }
        }
    }
    return !flag;
}

void Subset::operator+=(const int &a5) {
    A[a5] = true;
}

void Subset::operator-=(const int &a) {
    A[a] = false;
}
