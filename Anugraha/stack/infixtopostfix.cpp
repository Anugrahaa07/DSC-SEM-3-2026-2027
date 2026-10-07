#include <iostream>
using namespace std;

class Stack
{
    char arr[50];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        arr[++top] = x;
    }

    char pop()
    {
        return arr[top--];
    }

    char peek()
    {
        return arr[top];
    }

    int empty()
    {
        return top == -1;
    }
};

int priority(char x)
{
    if (x == '^')
        return 3;

    if (x == '*' || x == '/')
        return 2;

    return 1;
}

int main()
{
    string infix = "k+l-m*n+(o^p)*w/u/v*t+q";
    string postfix = "";

    Stack s;

    for (char x : infix)
    {
        if (x >= 'a' && x <= 'z')
            postfix += x;

        else if (x == '(')
            s.push(x);

        else if (x == ')')
        {
            while (s.peek() != '(')
                postfix += s.pop();

            s.pop();
        }

        else
        {
            while (!s.empty() &&
                   priority(s.peek()) >= priority(x))
            {
                postfix += s.pop();
            }

            s.push(x);
        }
    }

    while (!s.empty())
        postfix += s.pop();

    cout << "Postfix = " << postfix;

    return 0;
}