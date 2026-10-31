#include "array.h"
#include <iostream>

int main() {
    Polynomial p1, p2, result;
    int choice;
    int coeff, pow;

    do {
        std::cout << "\n==============================\n";
        std::cout << "    POLYNOMIAL OPERATIONS     \n";
        std::cout << "==============================\n";
        std::cout << "1. Insert term into Polynomial 1\n";
        std::cout << "2. Insert term into Polynomial 2\n";
        std::cout << "3. Display Polynomials\n";
        std::cout << "4. Add Polynomials (P1 + P2)\n";
        std::cout << "5. Multiply Polynomials (P1 * P2)\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter coefficient: ";
                std::cin >> coeff;
                std::cout << "Enter power: ";
                std::cin >> pow;
                p1.insertTerm(coeff, pow);
                std::cout << "Term inserted into Polynomial 1 successfully.\n";
                break;

            case 2:
                std::cout << "Enter coefficient: ";
                std::cin >> coeff;
                std::cout << "Enter power: ";
                std::cin >> pow;
                p2.insertTerm(coeff, pow);
                std::cout << "Term inserted into Polynomial 2 successfully.\n";
                break;

            case 3:
                std::cout << "\nPolynomial 1: ";
                p1.display();
                std::cout << "\nPolynomial 2: ";
                p2.display();
                std::cout << "\n";
                break;

            case 4:
                result = p1.add(p2);
                std::cout << "\nResult of Addition (P1 + P2): ";
                result.display();
                std::cout << "\n";
                break;

            case 5:
                result = p1.multiply(p2);
                std::cout << "\nResult of Multiplication (P1 * P2): ";
                result.display();
                std::cout << "\n";
                break;

            case 6:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice! Please choose between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}