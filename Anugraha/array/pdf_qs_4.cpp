#include<iostream>
using namespace std;

int main()
{
    int n, a[101];

    cout << "Enter number of digits: ";
    cin >> n;

    cout << "Enter digits: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] < 9)
        {
            a[i]++;
            break;
        }
        else
        {
            a[i] = 0;
        }
    }

    if(a[0] == 0)
    {
        for(int i = n; i > 0; i--)
            a[i] = a[i - 1];

        a[0] = 1;
        n++;
    }

    cout << "Result: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}