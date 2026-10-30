#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* create()
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

    return head;
}

Node* merge(Node *head1, Node *head2)
{
    Node *head = NULL, *temp = NULL, *newnode;

    while(head1 != NULL && head2 != NULL)
    {
        newnode = new Node;

        if(head1->data < head2->data)
        {
            newnode->data = head1->data;
            head1 = head1->next;
        }
        else
        {
            newnode->data = head2->data;
            head2 = head2->next;
        }

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while(head1 != NULL)
    {
        newnode = new Node;
        newnode->data = head1->data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        head1 = head1->next;
    }

    while(head2 != NULL)
    {
        newnode = new Node;
        newnode->data = head2->data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        head2 = head2->next;
    }

    return head;
}

int main()
{
    Node *head1, *head2, *head3, *temp;

    cout<<"Enter first sorted list\n";
    head1 = create();

    cout<<"Enter second sorted list\n";
    head2 = create();

    head3 = merge(head1, head2);

    cout<<"Merged list: ";

    temp = head3;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}