#include <iostream>
using namespace std;

#define MAX 5

class Deque
{
    int a[MAX], front, rear;

public:
    Deque()
    {
        front = rear = -1;
    }

    void insertFront(int x)
    {
        if (front == 0)
            cout << "Overflow\n";
        else
        {
            if (front == -1)
                front = rear = 0;
            else
                front--;

            a[front] = x;
        }
    }

    void insertRear(int x)
    {
        if (rear == MAX - 1)
            cout << "Overflow\n";
        else
        {
            if (front == -1)
                front = rear = 0;
            else
                rear++;

            a[rear] = x;
        }
    }

    void deleteFront()
    {
        if (front == -1)
            cout << "Underflow\n";
        else
        {
            cout << "Deleted: " << a[front] << endl;

            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }

    void deleteRear()
    {
        if (rear == -1)
            cout << "Underflow\n";
        else
        {
            cout << "Deleted: " << a[rear] << endl;

            if (front == rear)
                front = rear = -1;
            else
                rear--;
        }
    }

    void display()
    {
        if (front == -1)
            cout << "Deque is empty\n";
        else
        {
            for (int i = front; i <= rear; i++)
                cout << a[i] << " ";

            cout << endl;
        }
    }
};

int main()
{
    Deque d;
    int ch, x;

    do
    {
        cout << "\n1.Insert Front";
        cout << "\n2.Insert Rear";
        cout << "\n3.Delete Front";
        cout << "\n4.Delete Rear";
        cout << "\n5.Display";
        cout << "\n6.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cin >> x;
            d.insertFront(x);
            break;

        case 2:
            cin >> x;
            d.insertRear(x);
            break;

        case 3:
            d.deleteFront();
            break;

        case 4:
            d.deleteRear();
            break;

        case 5:
            d.display();
            break;
        }
    } while (ch != 6);

    return 0;
}