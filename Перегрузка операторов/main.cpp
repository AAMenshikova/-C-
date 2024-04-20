#include <iostream>
#include "head.h"

using namespace std;

int main() {
    //Вариант 11 - 1 и 7
    Complex complex1(3.5, 2.0);
    Complex complex2(4.0, 6.0);
    complex1.print(complex1 & 7.5);
    cout << '\n';
    complex1.print(complex1 + complex2);
    cout << '\n';
    complex1.print(complex1 * complex2);
    cout << '\n';
    cout << complex1.operator=(complex1);
    cout << '\n';
    cout << complex2.operator=(complex2);

    cout << '\n' << '\n';

    Subset set1(set1);

    Subset set2(set2);

    vector<bool> set3 = set1 + set2;
    for (int i = 0; i < 10; i++) {
        if (set3[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';

    cout << (set1 == set2);
    cout << '\n';

    cout << (set1 != set2);
    cout << '\n';

    set2 += 9;
    for (int i = 0; i < 10; i++) {
        if (set2.A[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';

    set1 -= 1;
    for (int i = 0; i < 10; i++) {
        if (set1.A[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}