#include <iostream>
#include <cmath>

using namespace std;

long long fact_odd(int n)
{
    long long y = 1;
    for (int i = 1; i <= n; i += 2)
    {
        y *= i;
    }

    return y;
}

long long fact_even(int n)
{
    long long y2 = 1;
    for (int i = 2; i <= n; i += 2)
    {
        y2 *= i;
    }
    return y2;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long res;
    if (n % 2 == 0)
    {
        res = fact_even(n);
    }
    else
    {
        res = fact_odd(n);
    }

    cout << "Result: " << res << endl;

    return 0;
}