// main.cpp
#include "Deque.cpp"

int main()
{
    char repeat;
    int choice, ele;
    Deque<int> dq;

    do
    {
        cout << "\n\t\t Menu" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Get Front Element" << endl;
        cout << "6. Get Rear Element" << endl;
        cout << "7. Display Deque Elements" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the element: ";
                cin >> ele;
                dq.insertFront(ele);
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> ele;
                dq.insertRear(ele);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << "Front Element: " << dq.getFront() << endl;
                break;
            case 6:
                cout << "Rear Element: " << dq.getRear() << endl;
                break;
            case 7:
                cout << dq;
                break;
            default:
                cout << "Invalid entry" << endl;
        }
        cout << "Do you want to continue(y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
