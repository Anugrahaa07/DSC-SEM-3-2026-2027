#include "array.h"

// --- Circular Linked List Functions ---
CircularLinkedList::CircularLinkedList()
{
    tail = NULL;
}

void CircularLinkedList::create()
{
    int num;
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

void CircularLinkedList::display()
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

int CircularLinkedList::length()
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

void CircularLinkedList::insertBeg(int item)
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

void CircularLinkedList::insertEnd(int item)
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

void CircularLinkedList::insertAtPos(int item, int pos)
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

void CircularLinkedList::deleteBeg()
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

void CircularLinkedList::deleteEnd()
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

void CircularLinkedList::deleteAtPos(int pos)
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


// --- Doubly Linked List Functions ---
DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
}

void DoublyLinkedList::create()
{
    int num;
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

void DoublyLinkedList::display()
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

void DoublyLinkedList::insertBeg(int item)
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

void DoublyLinkedList::insertEnd(int item)
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

void DoublyLinkedList::insertAtPos(int item, int pos)
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

void DoublyLinkedList::deleteBeg()
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

void DoublyLinkedList::deleteEnd()
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

void DoublyLinkedList::deleteAtPos(int pos)
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