#include <iostream>
using namespace std;

int main()
{
    unsigned k;
    double x;
    cout << "Enter k and x: ";
    cin >> k >> x;

    double dif = 0; //-x^2 /(2k)(2k-1)
    double x_k = 1;

    for (int i = 1; i <= k; i++)
    {
        dif = -x * x / ((2 * i) * (2 * i - 1));
        x_k *= dif;
    }

    cout << "res = " << x_k << endl;
    return 0;
}
