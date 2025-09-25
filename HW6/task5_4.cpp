#include <iostream>

using namespace std;

long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

double P_a(int n, long long fact = 1)
{
    if (n == 0)
        return 1.0;
    fact *= n;
    return P_a(n - 1, fact / n) * (1.0 + 1.0 / fact);
}

double P_b(int n, double pow2 = 1.0)
{
    if (n == 0)
        return 1.0;
    pow2 *= 2;
    double sign = (n % 2 == 0) ? -1.0 : 1.0; // (-1)^(n+1)
    return P_b(n - 1, pow2 / 2) * (1.0 + sign * n * n / pow2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "P_a(" << n << ") = " << P_a(n) << endl;
    cout << "P_b(" << n << ") = " << P_b(n) << endl;

    return 0;
}
