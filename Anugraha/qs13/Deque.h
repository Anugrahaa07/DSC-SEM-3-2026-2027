#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class Deque
{
    Node<T>* front;
    Node<T>* rear;

public:
    Deque();
    ~Deque();
    bool isEmpty();
    void insertFront(T key);
    void insertRear(T key);
    void deleteFront();
    void deleteRear();
    T getFront();
    T getRear();

    template <class U>
    friend ostream& operator<<(ostream& os, const Deque<U>& dq);
};

#endif
