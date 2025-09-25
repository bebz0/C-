#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long a = 1, b = 1; // a1 = 1, b1 = 1
    long long power2 = 1;   // 2^0 = 1
    long long fact = 1;     // 0! = 1
    double S = 0.0;

    for (int k = 1; k <= n; k++)
    {
        power2 *= 2; // 2^k = 2^(k-1) * 2
        fact *= k;   // k! = (k-1)! * k

        double term = (double)power2 / ((1 + a + b) * fact);
        S += term;

        long long new_a = 3 * b + 2 * a;
        long long new_b = 2 * a + b;
        a = new_a;
        b = new_b;
    }

    cout << "S_" << n << " = " << S << endl;
    return 0;
}
