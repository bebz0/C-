#include <iostream>
using namespace std;

double func(double arr[], int n)
{
    double maximum = 0;

    for (int k = 0; k < n; k++)
    {
        if (arr[k] > maximum)
        {
            maximum = arr[k];
        }
    }
    return maximum;
}

int main()
{
    const int n = 5;
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    cout << func(arr, n) << endl;
    return 0;
}