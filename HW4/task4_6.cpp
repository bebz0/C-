#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    double res = 0;
    double res2 = 0;
    for (int i = 0; i < n; i++)
    {
        res = sqrt(2 + res);
    }
    cout << "y1: " << res << endl;

    for (int k = n; k >= 1; k--)
    {
        res2 = sqrt(3 * k + res2);
    }
    cout << "y2: " << res2 << endl;

    return 0;
}
