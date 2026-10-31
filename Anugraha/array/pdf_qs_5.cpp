#include<iostream>
using namespace std;

int main()
{
    int n, a[100];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter stock prices: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int minprice = a[0];
    int maxprofit = 0;

    for(int i = 1; i < n; i++)
    {
        if(a[i] - minprice > maxprofit)
            maxprofit = a[i] - minprice;

        if(a[i] < minprice)
            minprice = a[i];
    }

    cout << "Maximum profit = " << maxprofit;

    return 0;
}