#include <iostream>
#include "head.h"

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    Swap_elements(a, b);
    cout << a << ' ' << b << "\n\n";

    try{
        Stack<int> stack1(4);
        //stack1.pop();
        //stack1.getTop();
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        stack1.push(4);
        cout << stack1.getTop() << '\n';
        stack1.push(5);
    }
    catch (Exceptions &exception) {
        cout << "Exception is: " << exception.what() << '\n';
    }
    return 0;
}
