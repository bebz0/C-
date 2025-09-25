#include <iostream>
using namespace std;

double func(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0 / i;
    }
    return sum;
}

int main()
{
    double a;
    cout << "Enter a: ";
    cin >> a;

    int n = 1;
    double sum = func(n);

    while (sum <= a)
    {
        n++;
        sum = func(n);
    }

    cout << "The first number is greater than " << a << ": " << sum
         << " (if n = " << n << ")" << endl;

    cout << "min n = " << n
         << ", 1 + 1/2 + ... + 1/n > " << a << endl;

    return 0;
}
