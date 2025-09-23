#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    int n;
    cout << "Enter x adn n: ";
    cin >> x >> n;
    if (n < 0)
    {
        cout << "n must be >= 0" << endl;
        return 1;
    }

    if (abs(x) >= 1)
    {
        cout << "|x| must be < 1" << endl;
        return 1;
    }
    double res = 1;
    double xi = 1;
    for (int i = 1; i <= n; i++)
    {
        xi *= x / i;
        res += xi;
    }
    cout << "res = " << res << endl;
    return 0;
}