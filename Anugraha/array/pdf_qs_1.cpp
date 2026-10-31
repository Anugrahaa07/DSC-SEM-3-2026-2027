#include<iostream>
using namespace std;

void sumsquare(int l[], int n, int result[])
{
    int odd = 0, even = 0;

    for(int i = 0; i < n; i++)
    {
        if(l[i] % 2 != 0)
            odd = odd + l[i] * l[i];
        else
            even = even + l[i] * l[i];
    }

    result[0] = odd;
    result[1] = even;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int l[100], result[2];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> l[i];

    sumsquare(l, n, result);

    cout << "Odd sum of squares = " << result[0] << endl;
    cout << "Even sum of squares = " << result[1];

    return 0;
}