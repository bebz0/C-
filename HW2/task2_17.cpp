#include <iostream>
#include <cmath>

using namespace std;

// sigmweight
double identity(double x)
{
    return x / (1.0 + exp(-x));
}

double identity_derivative(double x)
{
    double e = exp(-x);
    double den = 1.0 + e; // denominatorr
    return (1.0 + e + x * e) / (den * den);
}

int main()
{
    double x;
    cout << "Enter the x: ";
    if (!(cin >> x))
        return 0;

    cout << "Identity = " << identity(x) << endl;
    cout << "Identity_derivatiev = " << identity_derivative(x) << endl;
    return 0;
}