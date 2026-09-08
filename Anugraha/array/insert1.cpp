#include<iostream>
using namespace std;
int main(){
    int ub,a[100],pos,val,n;
    cout<<"Enter the size of the array"<<'\n';
    cin>>n;
    cout<<"Enter the array elements: "<<'\n';
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The array is: "<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Enter the upper bound of the array: "<<'\n';
    cin>>ub;
    cout<<"At which  index to we have to insert? "<<'\n';
    cin>>pos;
    cout<<"Which value do you need to insert? "<<'\n';
    cin>>val;
    for(int i=ub;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=val;
    ub=ub+1;
    for(int i=0;i<ub;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}