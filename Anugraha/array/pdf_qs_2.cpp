#include<iostream>
using namespace std;

int main()
{
    int n, target;
    int a[100];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target: ";
    cin >> target;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] + a[j] == target)
            {
                cout << "Indices: " << i << " " << j;
                return 0;
            }
        }
    }

    return 0;
}