#include "queue.h"

template <class T>
Queue<T>::Queue(int size)
{
    capacity = size;
    arr = new T[capacity];
    front = -1;
    rear = -1;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] arr;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (front == -1 || front > rear);
}

template <class T>
bool Queue<T>::isFull()
{
    return (rear == capacity - 1);
}

template <class T>
void Queue<T>::enqueue(T key)
{
    if (isFull())
    {
        cout << "Queue Overflow! Cannot insert element." << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    arr[rear] = key;
    cout << "Element inserted successfully." << endl;
}

template <class T>
void Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow! No elements to delete." << endl;
        return;
    }
    cout << "Deleted element: " << arr[front] << endl;
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

template <class T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return T();
    }
    return arr[front];
}

template <class U>
ostream& operator<<(ostream& os, const Queue<U>& q)
{
    if (q.front == -1 || q.front > q.rear)
    {
        os << "Queue is Empty" << endl;
        return os;
    }
    os << endl << "Queue elements (Front to Rear): ";
    for (int i = q.front; i <= q.rear; i++)
    {
        os << q.arr[i] << " ";
    }
    os << endl;
    return os;
}

