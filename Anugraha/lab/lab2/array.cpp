#include "array.h"

template <class T>
array<T>::array()
{
    lb = 1;
    ub = 0;
}

template <class T>
void array<T>::setlb(int a) { 
    lb = a; }

template <class T>
void array<T>::setub(int a) { 
    ub = a; }

template <class T>
void array<T>::create()
{
    cout << "Enter " << (ub - lb + 1) << " elements: ";
    for (int i = lb; i <= ub; i++)
        cin >> a[i];
}

template <class T>
void array<T>::display()
{
    for (int i = lb; i <= ub; i++)
        cout << a[i] << " ";
    cout << endl;
}
template <class T>
void array<T>::bubbleSort()
{
    for (int i = lb; i < ub; i++)
    {
        for (int j = lb; j <= ub - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
template <class T>
void array<T>::insertionSort()
{
    for (int i = lb + 1; i <= ub; i++)
    {
        T key = a[i];
        int j = i - 1;
        while (j >= lb && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
template <class T>
void array<T>::selectionSort()
{
    for (int i = lb; i < ub; i++)
    {
        int min = i;
        for (int j = i + 1; j <= ub; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        T temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
template <class T>
void array<T>::merge(int low, int mid, int high)
{
    T temp[100];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= high) temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

template <class T>
void array<T>::MergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

template <class T>
void array<T>::mergeSort()
{
    MergeSort(lb, ub);
}
template <class T>
int array<T>::partition(int low, int high)
{
    T pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    T temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return (i + 1);
}

template <class T>
void array<T>::quickSort(int low, int high)
{
    if (low < high)
    {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

template <class T>
void array<T>::QuickSort()
{
    quickSort(lb, ub);
}