#include<iostream>
using namespace std;

int main()
{
    int n, a[100];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0;

    for(int i = 0; i < n; i++)
    {
        result = result ^ a[i];
    }

    cout << "Single number = " << result;

    return 0;
}