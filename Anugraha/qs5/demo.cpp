#include "array.h"

int main()
{
    CircularLinkedList cll;
    DoublyLinkedList dll;
    int choice, subChoice, val, pos;
    char k;

   system("cls");
    do
    {
        cout << "\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            do
            {
                cout << "\n--- Circular Linked List ---" << endl;
                cout << " 1.Creation\n 2.Display\n 3.Insert at Beginning\n 4.Insert at End\n 5.Insert at a Position\n 6.Delete at Beginning\n 7.Delete at End\n 8.Delete at Position\n 9.Back\nEnter choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                    case 1: cll.create(); cll.display(); break;
                    case 2: cll.display(); break;
                    case 3: cout << "Value: "; cin >> val; cll.insertBeg(val); cll.display(); break;
                    case 4: cout << "Value: "; cin >> val; cll.insertEnd(val); cll.display(); break;
                    case 5: cout << "Value & Position: "; cin >> val >> pos; cll.insertAtPos(val, pos); cll.display(); break;
                    case 6: cll.deleteBeg(); cll.display(); break;
                    case 7: cll.deleteEnd(); cll.display(); break;
                    case 8: cout << "Pos: "; cin >> pos; cll.deleteAtPos(pos); cll.display(); break;
                }
            } while (subChoice >= 1 && subChoice <= 8);
        }
        else if (choice == 2)
        {
            do
            {
                cout << "\n--- Doubly Linked List ---" << endl;
                cout << " 1.Creation\n 2.Display\n 3.Insert at Beginning\n 4.Insert at End\n 5.Insert at a Position\n 6.Delete at Beginning\n 7.Delete at End\n 8.Delete at Position\n 9.Back\nEnter choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                    case 1: dll.create(); dll.display(); break;
                    case 2: dll.display(); break;
                    case 3: cout << "Value: "; cin >> val; dll.insertBeg(val); dll.display(); break;
                    case 4: cout << "Value: "; cin >> val; dll.insertEnd(val); dll.display(); break;
                    case 5: cout << "Value & Pos: "; cin >> val >> pos; dll.insertAtPos(val, pos); dll.display(); break;
                    case 6: dll.deleteBeg(); dll.display(); break;
                    case 7: dll.deleteEnd(); dll.display(); break;
                    case 8: cout << "Pos: "; cin >> pos; dll.deleteAtPos(pos); dll.display(); break;
                }
            } while (subChoice >= 1 && subChoice <= 8);
        }
        else if (choice == 3)
        {
            break;
        }

        cout << "\nContinue to main menu? ((y)Yes): ";
        cin >> k;
    } while (k == 1 || k == 'y' || k == 'Y');

    getch();
    return 0;
}