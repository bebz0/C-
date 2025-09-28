#include <iostream>
using namespace std;

// a) b_n = b + 1 / (b + 1 / (... + 1/b))
double func_a(int n, double b)
{
    double result = b;
    for (int i = 0; i < n; i++)
    {
        result = b + 1.0 / result;
    }
    return result;
}

// б) λ_n = 2 + 1 / (6 + 1 / (10 + ... + 1/(4n+2)))
double func_b(int n)
{
    double bk = 4 * n + 2; // b0 = 4n + 2
    for (int k = 1; k <= n; k++)
    {
        bk = 4 * (n - k) + 2 + 1.0 / bk;
    }
    return 2 + 1.0 / bk;
}

// в) x_{2n} = 1 + 1 / (2 + 1 / (1 + 1 / (2 + ... )))
double func_c(int n)
{
    double result = 1.0;
    for (int i = n; i >= 1; i--)
    {
        result = 2 + 1.0 / result;
        result = 1 + 1.0 / result;
    }
    return result;
}

int main()
{
    int n;
    double b;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter b for func_a): ";
    cin >> b;

    cout << "a) b_n = " << func_a(n, b) << endl;
    cout << "b) l_n = " << func_b(n) << endl;
    cout << "c) x_{2n} = " << func_c(n) << endl;

    return 0;
}
