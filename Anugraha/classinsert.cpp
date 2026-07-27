#include<iostream>
using namespace std;
template<class T>
class ReadData{
    public:
    T ub,a[100],n,j,lb,key;
    void readData();
    void InsertData();
};
template<class T>
void ReadData<T>::readData(){
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
    cout<<endl<<"Enter the upper bound of the array: "<<'\n';
    cin>>ub;
}
template<class T>
void ReadData<T>::InsertData(){
    for(int i=lb+1;i<=ub;i++){
        key=a[i];
        j=i-1;
        while (j>=lb && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;  
    }
        for(int i=lb;i<=ub;i++){
            cout<<a[i]<<" ";
        }
}
int main(){
ReadData<int>obj1;
obj1.readData();
obj1.InsertData();
return 0;
}