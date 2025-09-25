#include <iostream>
#include <cmath>

using namespace std;

double func(const double arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > exp(1))
        {
            sum += arr[i];
        }
    }
    delete arr;
    return sum;
}

int main()
{
    const int N = 10;
    double arr[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    cout << func(arr, N) << endl;
    return 0;
}