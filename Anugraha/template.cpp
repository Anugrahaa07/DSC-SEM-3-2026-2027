#include<iostream>
template<class T>
T large(T n1,T n2){
    return n1>n2 ? n1:n2;
}
int main(){
    std::cout<<large(1,2)<<'\n';
    std::cout<<large(2.3,5.9)<<'\n';
    std::cout<<large("hai","Anu")<<'\n';
    return 0;

}