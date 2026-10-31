#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
#include <ostream>
 
template <class T>
class array
{
    int lb, ub;   
    T a[100];     
 
    public:
    array();                              
    void setlb(int a);                   
    void setub(int a);                    
    int  getlb();                         
    int  getub();                         
    void create();                        
    void insertatend(T item);            
    void insertatbeginning(T item);      
    void insertatposition(int, T item);  
    void deleteatend();                 
    void deleteatbeginning();           
    void deleteatposition(int);         
    template<class U> friend ostream& operator<<(ostream&, const array<U>&);
};
