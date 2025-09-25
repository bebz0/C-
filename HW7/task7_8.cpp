#include <iostream>
using namespace std;

bool func(int x)
{
    return x > 0 && (x & (x - 1)) == 0;
}

const int N = 100;

void InputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void PrintArray(const int arr[], int n)
{
    cout << "(";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << ")";
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0 || n > N)
    {
        cout << "Incorrect dimension!" << endl;
        return 1;
    }

    int arr[N];
    InputArray(arr, n);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (func(arr[i]))
        {
            count++;
        }
    }

    cout << "Array: ";
    PrintArray(arr, n);
    cout << "\nCount of powers of two: " << count << endl;

    return 0;
}
