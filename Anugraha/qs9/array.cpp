#include "array.h"
#include <iostream>

using namespace std;

template <typename T>
Node<T>::Node(T val) {
    data = val;
    next = nullptr;
}

template <typename T>
stack<T>::stack() {
    top = nullptr;
}

template <typename T>
void stack<T>::push() {
    T item;
    cout << "enter the number to be inserted " << endl;
    cin >> item;
    Node<T>* newNode = new Node<T>(item);
    newNode->next = top;
    top = newNode;
}

template <typename T>
void stack<T>::pop() {
    if (top == nullptr) {
        cout << "Under flow" << endl;
    } else {
        Node<T>* temp = top;
        T item = temp->data;
        top = top->next;
        delete temp;
        cout << "deleted element is " << item << endl;
    }
}

template <typename T>
void stack<T>::display() {
    if (top == nullptr) {
        cout << "empty stack" << endl;
    } else {
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
}

template <typename T>
void stack<T>::peek() {
    if (top == nullptr) {
        cout << "empty stack" << endl;
    } else {
        cout << "Top element is " << top->data << endl;
    }
}

template class Node<int>;
template class stack<int>;