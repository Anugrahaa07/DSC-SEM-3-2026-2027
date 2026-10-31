template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val);
};

template <typename T>
class stack {
private:
    Node<T>* top;
public:
    stack();
    void push();
    void pop();
    void display();
    void peek();
};