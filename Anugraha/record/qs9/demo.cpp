#include "array.h"
#include <iostream>

using namespace std;

int main() {
    stack<int> obj;
    int choice, loop_ch;
    do {
        cout << "MENU" << endl;
        cout << "1.push" << endl;
        cout << "2.pop" << endl;
        cout << "3.Display" << endl;
        cout << "4.Display top element" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: obj.push(); break;
            case 2: obj.pop(); break;
            case 3: obj.display(); break;
            case 4: obj.peek(); break;
            default: cout << "invalid entry";
        }
        cout << "Do you want to repeat the operations\nEnter 1 to continue" << endl;
        cin >> loop_ch;
    } while (loop_ch == 1);
    return 0;
}