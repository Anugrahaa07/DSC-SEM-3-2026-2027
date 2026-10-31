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
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                pos=a[j+1];
                a[j+1]=a[j];
                a[j]=pos;
            }
        }
    }
    cout<<"The array is: "<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        return 0;
}
}