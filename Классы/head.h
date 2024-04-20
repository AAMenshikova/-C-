#ifndef _2_C___HEADER_H
#define _2_C___HEADER_H

#include <stack>

class Stack {
private:
    std::stack<int> stack1;
public:
    Stack();

    Stack(const Stack &stack);

    Stack(std::stack<int> &stack1);

    Stack(const Stack &stack1, const int &element);

    void push(const int &element);

    void pop();

    int count_elements();

    bool isEmpty();

    int getTop();

    void printStack();
};

#endif //_2_C___HEADER_H
