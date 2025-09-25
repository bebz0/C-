#include <iostream>
using namespace std;

void func(int arr[], int n)
{

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    cout << "Odd: " << odd << ", Even: " << even << endl;
}

int main()
{
    const int Max_N = 50;
    int arr[Max_N];
    int n = 0;

    cout << "Enter numbers: " << endl;

    while (n < Max_N)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            break;
        }
        arr[n++] = x;
    }

    func(arr, n);
    return 0;
}