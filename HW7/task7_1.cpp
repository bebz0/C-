#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    double x;
    cout << "Enter x: ";
    cin >> x;

    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < x)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}