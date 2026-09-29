#include<iostream>
#include<string>
template<class T>
class array{
    private:
    int n;
    T a[100];
    public:
    void readdata();
    T findarraysum(T a);
    void display();
};
template<typename T> void array<T>::readdata(){
    std::cout<<"Enter the size of the array: ";
    std::cin>>n;
    std::cout<<"Enter the elements: "<<'\n';
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
}
template<typename T> void array<T>::display(){
    std::cout<<"The elements: "<<'\n';
    for(int i=0;i<n;i++){
        std::cout<<a[i]<<'\t';
    }
}
template<typename T> T array<T>::findarraysum(T key){
    int s=0;
    for(int i=0;i<n;i++){
        s=a[i]+key+s;
    }
    return s;
}
int main(){
    array<int>obj1;
    obj1.readdata();
    obj1.display();
    std::cout<<
    std::cout<<"Array Sum: "<<obj1.findarraysum(3)<<'\n';
    return 0;
}
