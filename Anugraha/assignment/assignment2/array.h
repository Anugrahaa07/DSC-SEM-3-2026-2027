#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T>
class array
{
    int lb, ub;
    T a[100];
    void merge(int low, int mid, int high);
    void MergeSort(int low, int high);
    int partition(int low, int high);
    void quickSort(int low, int high);

public:
    array();
    void setlb(int a);
    void setub(int a);
    void create();
    void display();
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void mergeSort();
    void QuickSort();
};