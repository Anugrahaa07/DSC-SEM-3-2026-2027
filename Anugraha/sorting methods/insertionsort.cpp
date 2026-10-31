#include<iostream>
using namespace std;
template<class T>
class ReadData{
    public:
        T ub,a[100],n,j,lb,key,i;
        T ReadData(){
            cout<<"Enter the size of the array"<<'\n';
            cin>>n;
            cout<<"Enter the array elements: "<<'\n';
            for(i=0;i<n;i++){
                cin>>a[i];
            }
            cout<<"The array is: "<<'\n';
            for(i=0;i<n;i++){
            cout<<a[i]<<" ";
            }
            cout<<endl<<"Enter the lower bound of the array: "<<'\n';
            cin>>lb;
            cout<<endl<<"Enter the upper bound of the array: "<<'\n';
            cin>>ub;
        }
        T InsertData()::ReadData(){
            for(i=lb+1;i<=ub;i++){
                key=a[i];
                j=i-1;
                while (j>=lb && a[j]>key){
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=key;  
            }
            for(i=0;i<=ub;i++){
                cout<<a[i]<<" ";
            }
        }
}

int main(){
    ReadData<int>obj1;
    ReadData<double>obj2;
    std::cout<<obj1.InsertData();
    std::cout<<obj2.InsertData();
    return 0;
}
