#include "array.cpp"
#include<iostream>
using namespace std;
int main(){
    array1<int>obj1;
    array1<std::string>obj2;
    cout<<"Integer array: "<<'\n';
    obj1.displayarray1();
    cout<<endl<<"String Array: "<<'\n';
    obj2.displayarray1();
    std::cout<<endl;
    return 0;
}