#include<iostream>
#include<string>
template <class T>
class calculator
{
    private:
    T num1, num2;
public:
    calculator(T n1, T n2){
        num1 =n1;
        num2=n2;
    }
    T add(){
        return num1+num2;
    }
};
int main(){
    calculator<int> obj1(20,21);
    calculator<double> obj2(29.23,1.3);
    calculator <std::string> obj3("hai ","Anjana");
    std::cout<<obj1.add();
    std::cout<<obj2.add();
    std::cout<<obj3.add();
    return 0;
}
