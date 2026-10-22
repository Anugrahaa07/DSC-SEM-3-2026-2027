#include <iostream>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

// 1. Bubble Sort
void bubbleSort(int arr[], int n) {
    int a[100];
    for (int i = 0; i < n; i++) a[i] = arr[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "Bubble Sort    : "; printArray(a, n); cout << "\n";
}

// 2. Insertion Sort
void insertionSort(int arr[], int n) {
    int a[100];
    for (int i = 0; i < n; i++) a[i] = arr[i];
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    cout << "Insertion Sort : "; printArray(a, n); cout << "\n";
}

// 3. Selection Sort
void selectionSort(int arr[], int n) {
    int a[100];
    for (int i = 0; i < n; i++) a[i] = arr[i];
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
    cout << "Selection Sort : "; printArray(a, n); cout << "\n";
}

// 4. Merge Sort helper functions
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSortUtil(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortUtil(a, left, mid);
        mergeSortUtil(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void mergeSort(int arr[], int n) {
    int a[100];
    for (int i = 0; i < n; i++) a[i] = arr[i];
    mergeSortUtil(a, 0, n - 1);
    cout << "Merge Sort     : "; printArray(a, n); cout << "\n";
}

// 5. Quick Sort helper functions (Lomuto Partition)
int lomutoPartition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}

void quickSortUtil(int a[], int low, int high) {
    if (low < high) {
        int pi = lomutoPartition(a, low, high);
        quickSortUtil(a, low, pi - 1);
        quickSortUtil(a, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    int a[100];
    for (int i = 0; i < n; i++) a[i] = arr[i];
    quickSortUtil(a, 0, n - 1);
    cout << "Quick Sort     : "; printArray(a, n); cout << "\n";
}

// 6. Linear Search
void linearSearch(int arr[], int n, int key) {
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1)
        cout << "Linear Search: Element found at index " << found << "\n";
    else
        cout << "Linear Search: Element not found\n";
}

// 7. Binary Search
void binarySearch(int arr[], int n, int key) {
    int a[100];
    for (int i = 0; i < n; i++) a[i] = arr[i];
    
    // Sort array for binary search
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            found = mid;
            break;
        }
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (found != -1)
        cout << "Binary Search: Element found at sorted index " << found << "\n";
    else
        cout << "Binary Search: Element not found\n";
}

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    printArray(arr, n);
    cout << "\n\n--- SORTING RESULTS ---\n";
    bubbleSort(arr, n);
    insertionSort(arr, n);
    selectionSort(arr, n);
    mergeSort(arr, n);
    quickSort(arr, n);

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    linearSearch(arr, n, key);
    binarySearch(arr, n, key);

    return 0;
}