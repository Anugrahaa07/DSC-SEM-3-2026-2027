#include<iostream>
using namespace std;

int main()
{
    int n, target;
    int a[100];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target: ";
    cin >> target;

    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == target)
        {
            cout << "Position = " << mid;
            return 0;
        }
        else if(target > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Position = " << low;

    return 0;
}