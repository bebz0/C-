#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, x;
    cout << "Enter n, x after a space: ";
    cin >> n >> x;

    long long res = 0;
    long long xi = 1;
    for (int i = 1; i <= n; i++)
    {
        xi *= x;
        res += i * xi;
    }

    cout << "Result: " << res << endl;

    return 0;
}