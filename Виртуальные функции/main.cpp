#include <iostream>
#include "head.h"

using namespace std;

int main() {
//вариант 11: Равносторонний треугольник, Параллелограмм
    cout << "Text the count of figures, which you want to add\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        add_figure();
    }
    sort();
    cout << "Figures were sorted\n";
    print();
    clear_figure();
}