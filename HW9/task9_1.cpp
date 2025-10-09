#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    double *arr = new double[n];

    cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double sum_sq = 0;
    for (int i = 0; i < n; i++)
    {
        sum_sq += arr[i] * arr[i];
    }

    cout << "Res: " << sum_sq << endl;

    delete[] arr;
    return 0;
}
