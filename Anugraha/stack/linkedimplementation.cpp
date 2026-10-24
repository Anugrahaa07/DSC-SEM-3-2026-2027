#include<iostream>
using namespace std;
struct Node{
    Node * next;
    int data;
};
Node * top = 0;
void push(int x){
    Node * newnode = new Node;
    newnode->data= x;
    newnode->next= top;
    top=newnode;
}
void display(){
    Node * temp;
    temp=top;
    if(top==0){
        cout<<"The stack is empty\n";
    }
    else{
        while(temp != 0){
            cout<<temp->data;
            if(temp->next != 0){
                cout<<"->";
            }
            temp=temp->next;
        }
    }
}
void peek(){
    if(top==0){
        cout<<"The stack is empty";
    }
    else{
        cout<<"The top element is "<<top->data<<endl;
    }
}
void pop(){
    Node * temp;
    temp=top;
    if(top==0){
        cout<<"The stack is empty";
    }
    else{
        cout<<"The popped element is "<<top->data<<endl;
        top=top->next;
        free(temp);
    }
}
int main(){
    push(5);
    push(6);
    push(7);
    push(1);
    push(10);
    pop();
    pop();
    peek();
    display();
    return 0;
}
