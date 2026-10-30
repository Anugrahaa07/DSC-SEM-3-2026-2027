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
    Node *slow, *fast;
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

    // Create a loop for testing
    // Uncomment these lines to create a loop

    /*
    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head;
    */

    slow = head;
    fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            cout<<"Loop detected";
            return 0;
        }
    }

    cout<<"No loop detected";

    return 0;
}