#include <iostream>
#include "head.h"

using namespace std;

int main() {
    Stack stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.pop();
    cout << "Stack contains " << stack1.count_elements() << " elements" << '\n';
    if (!stack1.isEmpty()) {
        cout << "Stack isn't empty, it contains " << stack1.count_elements() << " elements" << '\n';
    } else {
        cout << "Stack is empty" << '\n';
    }
    cout << "Stack has element " << stack1.getTop() << " on the top" << '\n';
    cout << "Stack contains these elements: ";
    stack1.printStack();
    cout << '\n';
    Stack stack2(stack2, 3);
    return 0;
}