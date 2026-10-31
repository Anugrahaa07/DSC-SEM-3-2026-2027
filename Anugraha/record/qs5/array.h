#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>
class CircularLinkedList
{
private:
    struct node
    {
        T data;
        node *link;
    } *tail;

public:
    CircularLinkedList();
    void create();
    void display();
    int length();
    void insertBeg(T item);
    void insertEnd(T item);
    void insertAtPos(T item, int pos);
    void deleteBeg();
    void deleteEnd();
    void deleteAtPos(int pos);
};

template <typename T>
class DoublyLinkedList
{
private:
    struct node
    {
        T data;
        node *prev;
        node *next;
    } *head;

public:
    DoublyLinkedList();
    void create();
    void display();
    void insertBeg(T item);
    void insertEnd(T item);
    void insertAtPos(T item, int pos);
    void deleteBeg();
    void deleteEnd();
    void deleteAtPos(int pos);
};