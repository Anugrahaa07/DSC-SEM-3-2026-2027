#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head = NULL, *temp, *newnode;
    Node *first, *second;
    int n, k;

    cout<<"Enter number of nodes: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        newnode = new Node;

        cout<<"Enter data: ";
        cin>>newnode->data;

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    cout<<"Enter k: ";
    cin>>k;

    first = head;
    second = head;

    for(int i=0; i<k; i++)
    {
        if(first == NULL)
        {
            cout<<"Invalid k";
            return 0;
        }

        first = first->next;
    }

    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    cout<<"Kth node from last: "<<second->data;
    cout<<"\nAddress: "<<second;

    return 0;
}