#include<iostream>

using namespace std;
struct Node{
    int data;
    Node * next;
};

Node * head = NULL;

void create(){
    int n,value,i;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    for(i=0;i<n;i++){
        cout<<"Enter the value: ";
        cin>>value;
        Node * newNode = new Node;
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            Node * temp = head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}
void display(){
    Node * temp = head;
    if(head==NULL){
        cout<<"EMPTY";
    }
    while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<"->";
        }
        temp=temp->next;
    }
}

void create2(){
    int value;
    cout<<"\nWe are going to create a new node and insert it at the beggining";

    cout<<"\nEnter the new value: ";
    cin>>value;

    Node * newNode = new Node;
    newNode->data=value;
    newNode->next=head;

    head=newNode;
}
void display2(){
    Node * temp = head;
    if(head==NULL){
        cout<<"\nEMPTY";
        return;
    }
   while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<"->";
        }
        temp=temp->next;
    }
}
void create3(){
    int value;
    cout<<"\nWe are going to create a new node and insert it at the last";

    cout<<"\nEnter the new value: ";
    cin>>value;

    Node * newNode = new Node;
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
            head=newNode;
        }
        else{
            Node * temp = head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
}
void display3(){
     Node * temp = head;
    if(head==NULL){
        cout<<"\nEMPTY";
        return;
    }
   while(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<"->";
        }
        temp=temp->next;
    }
}
int main(){
    create();
    display();
    create3();
    display3();
    return 0;
}