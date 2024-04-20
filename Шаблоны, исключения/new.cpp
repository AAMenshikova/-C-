#include "head.h"
#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
void Swap_elements(T &a, T &b) {
    swap(a, b);
}

template<class T>
Node<T>::Node(T element) {
    value = element;
}

template<class T>
Stack<T>::Stack(int N) {
    size = 0;
    size_max = N;
    top = nullptr;
}

template<class T>
T Stack<T>::getTop() {
    if (size == 0) {
        throw Exceptions("Empty stack! Error");
    }
    return top->value;
}

template<class T>
void Stack<T>::pop() {
    if (size == 0) {
        throw Exceptions("Empty stack! Error");
    }
    Node<T> *tmp = top;
    top = top->next;
    delete (tmp);
    size--;
}

template<class T>
void Stack<T>::push(T val) {
    if (size == size_max) {
        throw Exceptions("Overloaded stack! Error");
    }
    Node<T> *new1 = new Node(val);
    new1->next = top;
    top = new1;
    size++;
}

Exceptions::Exceptions(char *msg) {
    char *mess = new char[strlen(msg) + 1];
    strcpy(mess, msg);
    message = mess;
}

const char *Exceptions::what() const noexcept {
    return message;
}

template
class Stack<int>;

template
class Stack<string>;

template
class Stack<double>;

template
class Stack<char>;

template
class Stack<float>;

template
class Stack<long long>;

template void Swap_elements(int &a, int &b);

template void Swap_elements(double &a, double &b);

template void Swap_elements(char &a, char &b);