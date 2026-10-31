#include "array.h"

// --- Circular Linked List Template Implementation ---
template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
    tail = NULL;
}

template <typename T>
void CircularLinkedList<T>::create()
{
    T num;
    char ch;
    do
    {
        cout << "Enter number: ";
        cin >> num;
        node *newnode = new node;
        newnode->data = num;
        if (tail == NULL)
        {
            tail = newnode;
            tail->link = newnode;
        }
        else
        {
            newnode->link = tail->link;
            tail->link = newnode;
            tail = newnode;
        }
        cout << "Continue (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

template <typename T>
void CircularLinkedList<T>::display()
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    node *temp = tail->link;
    cout << "List: ";
    while (temp->link != tail->link)
    {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << temp->data << endl;
}

template <typename T>
int CircularLinkedList<T>::length()
{
    if (tail == NULL) return 0;
    int count = 1;
    node *temp = tail->link;
    while (temp != tail)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

template <typename T>
void CircularLinkedList<T>::insertBeg(T item)
{
    node *newnode = new node;
    newnode->data = item;
    if (tail == NULL)
    {
        tail = newnode;
        tail->link = newnode;
    }
    else
    {
        newnode->link = tail->link;
        tail->link = newnode;
    }
}

template <typename T>
void CircularLinkedList<T>::insertEnd(T item)
{
    node *newnode = new node;
    newnode->data = item;
    if (tail == NULL)
    {
        tail = newnode;
        tail->link = newnode;
    }
    else
    {
        newnode->link = tail->link;
        tail->link = newnode;
        tail = newnode;
    }
}

template <typename T>
void CircularLinkedList<T>::insertAtPos(T item, int pos)
{
    int len = length();
    if (pos < 1 || pos > len + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) insertBeg(item);
    else if (pos == len + 1) insertEnd(item);
    else
    {
        node *newnode = new node;
        newnode->data = item;
        node *temp = tail->link;
        for (int i = 1; i < pos - 1; i++) temp = temp->link;
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

template <typename T>
void CircularLinkedList<T>::deleteBeg()
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    node *temp = tail->link;
    if (temp->link == temp)
    {
        tail = NULL;
        delete temp;
    }
    else
    {
        tail->link = temp->link;
        delete temp;
    }
}

template <typename T>
void CircularLinkedList<T>::deleteEnd()
{
    if (tail == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    node *temp = tail->link;
    if (temp->link == temp)
    {
        tail = NULL;
        delete temp;
    }
    else
    {
        node *prev = NULL;
        while (temp->link != tail->link)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = tail->link;
        tail = prev;
        delete temp;
    }
}

template <typename T>
void CircularLinkedList<T>::deleteAtPos(int pos)
{
    int len = length();
    if (pos < 1 || pos > len)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) deleteBeg();
    else
    {
        node *temp = tail->link;
        for (int i = 1; i < pos - 1; i++) temp = temp->link;
        node *nextnode = temp->link;
        temp->link = nextnode->link;
        if (nextnode == tail) tail = temp;
        delete nextnode;
    }
}


// --- Doubly Linked List Template Implementation ---
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
}

template <typename T>
void DoublyLinkedList<T>::create()
{
    T num;
    char ch;
    do
    {
        cout << "Enter number: ";
        cin >> num;
        node *newnode = new node;
        newnode->data = num;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL) head = newnode;
        else
        {
            node *temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
        cout << "Continue (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

template <typename T>
void DoublyLinkedList<T>::display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    node *temp = head;
    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
void DoublyLinkedList<T>::insertBeg(T item)
{
    node *newnode = new node;
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL) head = newnode;
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertEnd(T item)
{
    node *newnode = new node;
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL) head = newnode;
    else
    {
        node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAtPos(T item, int pos)
{
    if (pos == 1) { insertBeg(item); return; }
    node *newnode = new node;
    newnode->data = item;
    node *temp = head;
    int i = 1;
    while (temp != NULL && i < pos - 1) { temp = temp->next; i++; }
    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        delete newnode;
    }
    else
    {
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newnode;
        temp->next = newnode;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteBeg()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    node *temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::deleteAtPos(int pos)
{
    if (pos == 1) { deleteBeg(); return; }
    node *temp = head;
    int i = 1;
    while (temp != NULL && i < pos) { temp = temp->next; i++; }
    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        return;
    }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    delete temp;
}

// Explicit instantiation for integer type
template class CircularLinkedList<int>;
template class DoublyLinkedList<int>;