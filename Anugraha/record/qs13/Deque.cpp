#include "Deque.h"

template <class T>
Deque<T>::Deque()
{
    front = NULL;
    rear = NULL;
}

template <class T>
Deque<T>::~Deque()
{
    while (!isEmpty())
    {
        deleteFront();
    }
}

template <class T>
bool Deque<T>::isEmpty()
{
    return (front == NULL);
}

template <class T>
void Deque<T>::insertFront(T key)
{
    Node<T>* newNode = new Node<T>(key);
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    cout << "Inserted " << key << " at front." << endl;
}

template <class T>
void Deque<T>::insertRear(T key)
{
    Node<T>* newNode = new Node<T>(key);
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Inserted " << key << " at rear." << endl;
}

template <class T>
void Deque<T>::deleteFront()
{
    if (isEmpty())
    {
        cout << "Deque Underflow! Cannot delete from front." << endl;
        return;
    }
    Node<T>* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    cout << "Deleted " << temp->data << " from front." << endl;
    delete temp;
}

template <class T>
void Deque<T>::deleteRear()
{
    if (isEmpty())
    {
        cout << "Deque Underflow! Cannot delete from rear." << endl;
        return;
    }
    Node<T>* temp = rear;
    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    cout << "Deleted " << temp->data << " from rear." << endl;
    delete temp;
}

template <class T>
T Deque<T>::getFront()
{
    if (isEmpty())
    {
        cout << "Deque is Empty! ";
        return T();
    }
    return front->data;
}

template <class T>
T Deque<T>::getRear()
{
    if (isEmpty())
    {
        cout << "Deque is Empty! ";
        return T();
    }
    return rear->data;
}

template <class U>
ostream& operator<<(ostream& os, const Deque<U>& dq)
{
    if (dq.front == NULL)
    {
        os << "Deque is empty." << endl;
        return os;
    }
    Node<U>* temp = dq.front;
    os << "Deque elements: ";
    while (temp != NULL)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << endl;
    return os;
}
