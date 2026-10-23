#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template <class T>
class Queue
{
    int front, rear, capacity;
    T* arr;
public:
    Queue(int size = 100);
    ~Queue();
    void enqueue(T key);
    void dequeue();
    T peek();
    bool isEmpty();
    bool isFull();
    template <class U>
    friend ostream& operator<<(ostream&, const Queue<U>&);
};
