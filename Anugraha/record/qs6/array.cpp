#include "array.h"
#include <iostream>

Node::Node(int c, int p) {
    coeff = c;
    pow = p;
    next = nullptr;
}

Polynomial::Polynomial() {
    head = nullptr;
}

Polynomial::~Polynomial() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void Polynomial::insertTerm(int c, int p) {
    if (c == 0) return;
    Node* newNode = new Node(c, p);
    if (head == nullptr || head->pow < p) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->pow > p) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr && current->pow == p) {
            current->coeff += c;
            delete newNode;
            if (current->coeff == 0) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
            }
        } else {
            newNode->next = current;
            if (prev == nullptr) {
                head = newNode;
            } else {
                prev->next = newNode;
            }
        }
    }
}

void Polynomial::display() const {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "0";
        return;
    }
    bool first = true;
    while (current != nullptr) {
        if (!first && current->coeff > 0) {
            std::cout << " + ";
        } else if (current->coeff < 0) {
            std::cout << " - ";
        }
        int absCoeff = (current->coeff < 0) ? -current->coeff : current->coeff;
        if (current->pow == 0) {
            std::cout << absCoeff;
        } else if (current->pow == 1) {
            std::cout << absCoeff << "x";
        } else {
            std::cout << absCoeff << "x^" << current->pow;
        }
        first = false;
        current = current->next;
    }
}

Polynomial Polynomial::add(const Polynomial& other) const {
    Polynomial result;
    Node* p1 = head;
    Node* p2 = other.head;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->pow == p2->pow) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                result.insertTerm(sum, p1->pow);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            result.insertTerm(p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            result.insertTerm(p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    while (p1 != nullptr) {
        result.insertTerm(p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        result.insertTerm(p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

Polynomial Polynomial::multiply(const Polynomial& other) const {
    Polynomial result;
    for (Node* p1 = head; p1 != nullptr; p1 = p1->next) {
        for (Node* p2 = other.head; p2 != nullptr; p2 = p2->next) {
            int c = p1->coeff * p2->coeff;
            int p = p1->pow + p2->pow;
            result.insertTerm(c, p);
        }
    }
    return result;
}