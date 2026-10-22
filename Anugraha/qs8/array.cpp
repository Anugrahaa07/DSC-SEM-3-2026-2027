#include "array.h"
#include <iostream>

using namespace std;

stack::stack()
{
    top = -1;
}

void stack::push()
{
    int item;
    if (top == 99)
    {
        cout << "overflow" << endl;
    }
    else
    {
        cout << "enter the number to be inserted " << endl;
        cin >> item;
        top++;
        arr[top] = item;
    }
}

void stack::pop()
{
    int item;
    if (top == -1)
    {
        cout << "Under flow" << endl;
    }
    else
    {
        item = arr[top];
        top--;
        cout << "deleted element is " << item << endl;
    }
}

void stack::display()
{
    int i;
    if (top == -1)
    {
        cout << "empty stack" << endl;
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
}

void stack::peek()
{
    if (top == -1)
    {
        cout << "empty stack" << endl;
    }
    else
    {
        cout << "Top element is " << arr[top] << endl;
    }
}