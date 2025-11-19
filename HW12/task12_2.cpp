#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of numbers (n): ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Size of n must be >0" << endl;
        return 1;
    }

    unsigned long long *numbers = new unsigned long long[n];
    unsigned long long totalSum = 0;

    cout << "Enter " << n << " numbers  by space: " << endl;

    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
        totalSum += numbers[i];
    }

    cout << "\nSum: " << totalSum << endl;
    delete[] numbers;
    return 0;
}