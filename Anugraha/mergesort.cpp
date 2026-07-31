#include<iostream>
using namespace std;
void Merge(int a[100],int lb,int mid,int ub);
void MergeSort(int a[100],int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(lb+ub)/2;
        MergeSort(a,lb,mid);
        MergeSort(a,mid+1,ub);
        Merge(a,lb,mid,ub);
    }
}
void Merge(int a[100],int lb,int mid,int ub){
    int i=lb,j=mid+1,k=lb,b[100];
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++){
        a[k]=b[k];
    }
}
int main(){
    int ub,a[100],lb,n,k;
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
    cout<<endl<<"Enter the lower bound of the array: "<<'\n';
    cin>>lb;
    cout<<"Enter the upper bound of the array: "<<'\n';
    cin>>ub;
    MergeSort(a,lb,ub);
    for(k=lb;k<=ub;k++){
        cout<<a[k]<<" ";
    }
    return 0;
}