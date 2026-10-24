#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top = -1;
void push(){
    int val;
    cout<<"Enter the number to enter the stack: ";
    cin>>val;
    if(top==N-1){
        cout<<"The stack is full\n";
    }
    else{
        top++;
        stack[top]=val;
    }
}
void pop(){
    int item;
    if(top==-1){
        cout<<"The stack is empty\n";
    }
    else{
        item=stack[top];
        top--;
    }
    cout<<"The popped value is "<<item<<endl;
}
void peek(){
    if(top==-1){
        cout<<"The stack is empty\n";
    }
    else{
        cout<<"The topmost element is "<<stack[top];
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        cout<<stack[i]<<"->";
    }
}
int main(){
    push();
    push();
    push();
    push();
    push();
    pop();
    pop();
    display();
    return 0;
}