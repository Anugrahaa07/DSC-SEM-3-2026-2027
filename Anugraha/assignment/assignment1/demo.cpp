#include "array.cpp"
 
int main()
{
    char repeat;
    int choice;
    int pos, element, l, u;
    array<int> arr;
 
    do
    {
        cout << "\t\t~MENU~" << endl;
        cout << "----------" << endl;
        cout << "1.create an array with user input: " << endl;
        cout << "2.insertion at beginning: " << endl;
        cout << "3.insertion at a specific position: " << endl;
        cout << "4.Insertion at end: " << endl;
        cout << "5.Deletion from beginning: " << endl;
        cout << "6.Deletion at specific position: " << endl;
        cout << "7.Deletion from end: " << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
 
        switch (choice)
        {
            case 1:
                cout << "Enter the lower bound: " << endl;
                cin >> l;
                arr.setlb(l);
                cout << "Enter the upper bound: " << endl;
                cin >> u;
                arr.setub(u);
                arr.create();
                break;
 
            case 2:
                cout << "Enter the element: " << endl;
                cin >> element;
                arr.insertatbeginning(element);
                cout << arr; 
                break;
 
            case 3:
                cout << "enter the position: " << "("<< arr.getlb() << "--" << arr.getub() << ")";
                cin >> pos;
                cout << "Enter the element: " << endl;
                cin >> element;
                arr.insertatposition(pos, element);
                cout << arr; 
                break;
 
            case 4:
                cout << "Enter the element" << endl;
                cin >> element;
                arr.insertatend(element);
                cout << arr; 
                break;
 
            case 5:
                arr.deleteatbeginning();
                cout << arr; 
                break;
 
            case 6:
                cout << "enter the position: " << "("<< arr.getlb() << "--" << arr.getub() << ")";
                cin >> pos;
                arr.deleteatposition(pos);
                cout << "element deleted" << endl;
                cout << arr; 
                break;
 
            case 7:
                arr.deleteatend();
                cout << arr; 
                break;

            default:
                cout << "The Entry is INVALID\nPlease try again" << endl;
        }
 
        cout << "Press 'y' to continue and 'n to stop'..." << endl;
        cin >> repeat;
 
    } while (repeat == 'y'); 
    return 0;
}
