#include<iostream>
using namespace std;

int remdup(int l[], int n, int result[])
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int flag = 0;

        for(int j = 0; j < count; j++)
        {
            if(l[i] == result[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            result[count] = l[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int n, l[100], result[100];

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> l[i];

    int count = remdup(l, n, result);

    cout << "Array after removing duplicates: ";

    for(int i = 0; i < count; i++)
        cout << result[i] << " ";

    cout << "\nNumber of unique elements = " << count;

    return 0;
}