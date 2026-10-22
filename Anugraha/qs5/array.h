#include<iostream>
#include <conio.h>
using namespace std;

class CircularLinkedList
{
private:
    struct node
    {
        int data;
        node *link;
    } *tail;

public:
    CircularLinkedList();
    void create();
    void display();
    int length();
    void insertBeg(int item);
    void insertEnd(int item);
    void insertAtPos(int item, int pos);
    void deleteBeg();
    void deleteEnd();
    void deleteAtPos(int pos);
};

class DoublyLinkedList
{
private:
    struct node
    {
        int data;
        node *prev;
        node *next;
    } *head;

public:
    DoublyLinkedList();
    void create();
    void display();
    void insertBeg(int item);
    void insertEnd(int item);
    void insertAtPos(int item, int pos);
    void deleteBeg();
    void deleteEnd();
    void deleteAtPos(int pos);
};