#ifndef INC_3__C___HEAD_H
#define INC_3__C___HEAD_H

#include <vector>
#include <set>

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double real, double imaginary);

    Complex(const Complex &c);

    Complex operator&(const double &c);

    Complex operator+(const Complex &complex2);

    Complex operator*(const Complex &complex2);

    double operator=(const Complex &complex1);

    void print(Complex complex);
};

class Subset {
public:
    bool A[10]{false};
    Subset(Subset &subset1);

    std::vector<bool> operator+(const Subset &subset2);

    bool operator==(const Subset &subset2);

    bool operator!=(const Subset &subset);

    void operator+=(const int &a5);

    void operator-=(const int &a);
};

#endif //INC_3__C___HEAD_H
