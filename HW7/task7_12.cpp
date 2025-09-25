#include <iostream>
using namespace std;

const int N = 100;

void InputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void func(int arr[], int n)
{
    int max_count = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > max_count)
        {
            max_count = count;
        }
    }

    cout << "Numbers that appear most frequently (" << max_count << " times): ";
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        bool alr_printed = false;
        for (int k = 0; k < i; k++)
        {
            if (arr[k] == arr[i])
            {
                alr_printed = true;
                break;
            }
        }
        if (!alr_printed && count == max_count)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int A[N];
    int n;

    cout << "Enter the number of elements (max " << N << "): ";
    cin >> n;

    InputArray(A, n);

    func(A, n);

    return 0;
}
