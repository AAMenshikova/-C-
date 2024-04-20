#ifndef INC_5____HEAD_H
#define INC_5____HEAD_H

#include <exception>
#include <iostream>

using namespace std;

template<typename T>
void Swap_elements(T &a, T &b);

template<class T>
class Node {
public:
    T value;
    Node *next;

    Node(T element);
};

template<class T>
class Stack {
private:
    Node<T> *top;
    int size;
    int size_max;
public:
    Stack(int N);

    T getTop();

    void pop();

    void push(T element);
};

class Exceptions : public exception {
private:
    char *message;
public:
    Exceptions(char *msg);

    const char *what() const noexcept override;
};

#endif //INC_5____HEAD_H
