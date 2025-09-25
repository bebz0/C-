#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    double a_prev2, a_prev1, a_k;
    double b_prev2, b_prev1, b_k;
    double S_n = 0.0;
    double power_of_2 = 2.0; // 2^k

    if (n >= 1)
    {
        a_prev2 = 0; // a_1
        b_prev2 = 1; // b_1
        S_n += 2.0 / (a_prev2 + b_prev2);
    }

    if (n >= 2)
    {
        a_prev1 = 1; // a_2
        b_prev1 = 0; // b_2
        S_n += 4.0 / (a_prev1 + b_prev1);
        power_of_2 = 4.0;
    }

    for (int k = 3; k <= n; k++)
    {
        power_of_2 *= 2; // 2^k = 2^(k-1) * 2
        a_k = a_prev1 / k + a_prev2 * b_prev1;
        b_k = b_prev1 + a_prev1;

        S_n += power_of_2 / (a_k + b_k);

        a_prev2 = a_prev1;
        a_prev1 = a_k;
        b_prev2 = b_prev1;
        b_prev1 = b_k;
    }

    cout << "S_n = " << S_n << endl;

    return 0;
}