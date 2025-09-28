#include <iostream>
using namespace std;

int main()
{
    int arr[4] = {5, 112, 4, 3};
    int rev[4];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        rev[i] = arr[n - i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << rev[i] << " ";
    }

    return 0;
}