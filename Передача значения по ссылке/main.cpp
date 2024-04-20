#include <iostream>
#include "head.h"

using namespace std;

int main() {
    int a1, b1;
    cin >> a1 >> b1;
    int a2 = a1;
    int b2 = b1;
    func1_1(a1, b1);
    func1_2(&a2, &b2);
    cout << a1 << ' ' << b1 << '\n';
    cout << a2 << ' ' << b2;

    cout << '\n';

    double x1;
    cin >> x1;
    double x2 = x1;
    func2_1(x1);
    func2_2(&x2);
    cout << x1 << '\n';
    cout << x2;

    cout << '\n';

    int r1, d1;
    cin >> r1 >> d1;
    int r2 = r1;
    int d2 = d1;
    func3_1(r1, d1);
    func3_2(&r2, &d2);
    cout << r1 << '\n';
    cout << r2;

    cout << '\n';

    int x[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    int y[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    func4_1(x);
    func4_2(&y);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << x[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << y[i][j] << ' ';
        }
        cout << '\n';
    }
}