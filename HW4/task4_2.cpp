#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long res1 = 1;
    cout << "Ascending factorial : ";
    for (int i = 1; i <= n; i++)
    {
        res1 *= i;
        cout << i;
        if (i != n)
            cout << "*";
    }
    cout << " = " << res1 << endl;

    long long res2 = 1;
    cout << "Descending factorial: ";
    for (int i = n; i >= 1; i--)
    {
        res2 *= i;
        cout << i;
        if (i != 1)
            cout << "*";
    }
    cout << " = " << res2 << endl;

    return 0;
}