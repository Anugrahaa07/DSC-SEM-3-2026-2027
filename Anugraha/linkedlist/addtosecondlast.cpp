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
    int n;

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

    newnode = new Node;

    cout<<"Enter element to insert: ";
    cin>>newnode->data;

    if(head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else if(head->next == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    cout<<"Updated list: ";

    temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}