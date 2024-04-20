#ifndef _1_C___HEADER_H
#define _1_C___HEADER_H


void func1_1(int &a, int &b);

void func1_2(int *a, int *b);

void func2_1(double &x);

void func2_2(double *x);

void func3_1(int &r, int &d);

void func3_2(int *r, int *d);

void func4_1(int (&x)[3][3]);

void func4_2(int (*x)[3][3]);

#endif /* _1_C___HEADER_H */