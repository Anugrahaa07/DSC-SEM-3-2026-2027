#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T>
class array
{
    // ... rest of your header file stays the same
    int lb, ub;
    T a[100];

    // Helpers for Merge and Quick Sort
    void merge(int low, int mid, int high);
    void mergeSortHelper(int low, int high);
    int partition(int low, int high);
    void quickSortHelper(int low, int high);

public:
    array();
    void setLB(int x);
    void setUB(int x);
    void create();
    void display();

    // 5 Sorting Algorithms
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void mergeSort();
    void quickSort();
};