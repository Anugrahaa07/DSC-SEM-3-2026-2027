#include "array.h"

int main()
{
    CircularLinkedList<int> cll;
    DoublyLinkedList<int> dll;
    int choice, subChoice, val, pos;
    char k;

    do
    {
        cout<<"----------MENU-----------";
        cout << "\n1. Circular Linked List\n2. Doubly Linked List\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            do
            {
                cout << "\n--- Circular Linked List ---" << endl;
                cout << "1.Create 2.Display 3.InsBeg 4.InsEnd 5.InsPos 6.DelBeg 7.DelEnd 8.DelPos 9.Back\nEnter choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                    case 1: cll.create(); cll.display(); break;
                    case 2: cll.display(); break;
                    case 3: cout << "Val: "; cin >> val; cll.insertBeg(val); cll.display(); break;
                    case 4: cout << "Val: "; cin >> val; cll.insertEnd(val); cll.display(); break;
                    case 5: cout << "Val & Pos: "; cin >> val >> pos; cll.insertAtPos(val, pos); cll.display(); break;
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
                cout << "1.Create 2.Display 3.InsBeg 4.InsEnd 5.InsPos 6.DelBeg 7.DelEnd 8.DelPos 9.Back\nEnter choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                    case 1: dll.create(); dll.display(); break;
                    case 2: dll.display(); break;
                    case 3: cout << "Val: "; cin >> val; dll.insertBeg(val); dll.display(); break;
                    case 4: cout << "Val: "; cin >> val; dll.insertEnd(val); dll.display(); break;
                    case 5: cout << "Val & Pos: "; cin >> val >> pos; dll.insertAtPos(val, pos); dll.display(); break;
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

        cout << "\nContinue to main menu? (1-Yes): ";
        cin >> k;
    } while (k == 1 || k == 'y' || k == 'Y');

    return 0;
}