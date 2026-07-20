#include<iostream>
using namespace std;
int main(){
    int n,lb,ub,val,a[100];
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
    cout<<"Enter which number you want to insert: "<<'\n';
    cin>>val;
    for(int i=lb;i<=ub;i--){
        a[i+1]=a[i];
    }
    a[lb]=val;
    cout<<"The new array is: "<<'\n';
    for(int i=lb;i<=ub;i++){
        cout<<a[i]<<" ";
    }
    ub=ub+1;
    return 0;
}
