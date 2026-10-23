#include "queue.cpp"

int main()
{
    char repeat;
    int choice, size, ele;

    cout << "Enter capacity of the queue: ";
    cin >> size;
    Queue<int> q(size);

    do
    {
        cout << "\n\t\t Queue Menu" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Delete)" << endl;
        cout << "3. Peek (Front Element)" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display Queue" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> ele;
            q.enqueue(ele);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Front element: " << q.peek() << endl;
            break;
        case 4:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is NOT Empty." << endl;
            break;
        case 5:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is NOT Full." << endl;
            break;
        case 6:
            cout << q;
            break;
        default:
            cout << "Invalid entry" << endl;
        }

        cout << "Do you want to continue (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
