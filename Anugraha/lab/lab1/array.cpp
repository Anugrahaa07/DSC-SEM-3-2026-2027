#include "array.h"
template <class T>
void array<T>::setlb(int a)
{
    lb = a;
}
 
template <class T>
void array<T>::setub(int a)
{
    ub = a;
}
 
template <class T>
int array<T>::getlb()
{
    return lb;
}
 
template <class T>
int array<T>::getub()
{
    return ub;
}
template <class T>
array<T>::array()
{
    lb = 1;
    ub = 0;
    for (int i = lb; i <= ub; i++)
        a[i] = 0;
}
template <class T>
void array<T>::create()
{
    int i;
    cout << "enter the elements: ";
    for (i = lb; i <= ub; i++)
        cin >> a[i];
}
template <class T>
void array<T>::insertatbeginning(T item)
{
    for (int i = ub; i >= lb; i--)
    {
        a[i + 1] = a[i];
    }
    a[lb] = item;
    ub = ub + 1;
}
template <class T>
void array<T>::insertatend(T item)
{
    int pos = ub + 1;
    a[pos] = item;
    ub = ub + 1;
}
template <class T>
void array<T>::insertatposition(int p, T item)
{
    if (p > ub || p < lb)
    {
        cout << "invalid position" << endl;
        return;
    }
 
    for (int i = ub; i >= p; i--)
    {
        a[i + 1] = a[i];
    }
    a[p] = item;
    ub = ub + 1;
}
template <class T>
void array<T>::deleteatend()
{
    ub = ub - 1;
}
template <class T>
void array<T>::deleteatbeginning()
{
    for (int i = lb; i <= ub - 1; i++)
    {
        a[i] = a[i + 1];
    }
    ub = ub - 1;
}
template <class T>
void array<T>::deleteatposition(int p)
{
    if (p > ub || p < lb)
    {
        cout << "invalid position" << endl;
        return;
    }
    for (int i = p; i <= ub - 1; i++)
    {
        a[i] = a[i + 1];
    }
    ub = ub - 1;
}
template <class U>
ostream& operator<<(ostream& os, const array<U>& m)
{
    int i;
    os << endl;
    for (i = m.lb; i <= m.ub; i++)
        os << m.a[i] << " ";
    os << endl;
    return os;
}
