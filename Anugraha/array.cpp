#include"array.h"
#include<iostream>
template<class T>
array1<T>::array1(){
    int i;
    std::cout<<"Enter the lower bound: ";
    std::cin>>lb;
    std::cout<<"Enter the upper bound: ";
    std::cin>>ub;
    std::cout<<"Enter the elements: "<<'\n';
    for(i=lb;i<ub;i++){
        std::cin>>a[i];
    }
}
template<class T>
void array1<T>::displayarray1(){
    int i;
    for(i=lb;i<ub;i++){
        std::cout<<a[i]<<" ";
    }
}