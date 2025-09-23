#include <iostream>
using namespace std;

// D(0)=1, D(1)=0, D(n)=(n−1)(D(n−1) + D(n−2)), D(n)=!n;  recursion
unsigned long long func(unsigned n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    unsigned long long d0 = 1; // D(0)
    unsigned long long d1 = 0; // D(1)
    for (unsigned i = 2; i <= n; ++i)
    {
        unsigned long long di = (i - 1) * (d1 + d0);
        d0 = d1;
        d1 = di;
    }
    return d1;
}

int main()
{
    int n;
    cout << "Enter n, n < 25 : ";
    cin >> n;

    if (n >= 25)
    {
        cout << "n must be < 25" << endl;
        return 1;
    }

    cout << func(n) << endl;
    return 0;
}