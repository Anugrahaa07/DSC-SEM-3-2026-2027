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
    int n, x;

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

    if(head == NULL || head->next == NULL)
    {
        cout<<"Second last node does not exist";
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
            temp = temp->next;

        cout<<"Second last node: "<<temp->data;
        cout<<"\nAddress: "<<temp;
    }

    return 0;
}