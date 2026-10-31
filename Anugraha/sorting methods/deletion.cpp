#include<iostream>
using namespace std;
int main(){
    int n,lb,ub,pos,a[100];
    cout<<"Enter the size of the array: "<<'\n';
    cin>>n;
    cout<<"Enter the elements of the array: "<<'\n';
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The array elements are: "<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<'\n';
    }
    cout<<"Enter the lower bound of the array: "<<'\n';
    cin>>lb;
    cout<<"Enter the upper bound of the array: "<<'\n';
    cin>>ub;
    cout<<"Enter the position of the number you want to delete: "<<'\n';
    cin>>pos;
    for(int i=pos;i<ub;i++){
        a[i]=a[i+1];
    }
    ub=ub-1;
    for(int i=lb;i<ub;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
    