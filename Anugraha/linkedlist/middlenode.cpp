#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

int main()
{
    Node *head = NULL, *temp, *newnode;
    Node *slow, *fast;
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        newnode = new Node;

        cout<<"Enter data: ";
        cin>>newnode->data;

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    if(head == NULL)
    {
        cout<<"List is empty";
        return 0;
    }

    slow = head;
    fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout<<"Middle node: "<<slow->data;
    cout<<"\nAddress: "<<slow;

    return 0;
}