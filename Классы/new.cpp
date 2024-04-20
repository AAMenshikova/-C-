#include "head.h"
#include <stack>
#include <iostream>

using namespace std;

Stack::Stack() = default;

Stack::Stack(const Stack &stack1) {
    stack<int> stack2 = (const stack<int> &) stack1;
}

Stack::Stack(std::stack<int> &stack) {
    stack1 = stack;
}

Stack::Stack(const Stack &stack1, const int &element) {
    stack<int> stack2 = (const stack<int> &) stack1;
    if (stack2.size() >= element) {
        cout << "Can't add element, stack is full";
    }
    else {
        cout << "Stack can add elements";
    }
}

void Stack::push(const int &element) {
    stack1.push(element);
    cout << "The element " << element << " was added in stack" << '\n';
}

void Stack::pop() {
    cout << "The element " << stack1.top() << " was deleted out of the stack" << '\n';
    stack1.pop();
}

int Stack::count_elements() {
    return stack1.size();
}

bool Stack::isEmpty() {
    return stack1.empty();
}

int Stack::getTop() {
    return stack1.top();
}

void Stack::printStack() {
    stack<int> stack2 = stack1;
    while (!stack2.empty()) {
        cout << stack2.top() << ' ';
        stack2.pop();
    }
}
