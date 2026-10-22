class Node {
public:
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p);
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial();
    ~Polynomial();
    void insertTerm(int c, int p);
    void display() const;
    Polynomial add(const Polynomial& other) const;
    Polynomial multiply(const Polynomial& other) const;
};