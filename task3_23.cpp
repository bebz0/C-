#include <iostream>
#include <cmath>

using namespace std;

double softExponential(double a, double x)
{

    if (a < 0) // a<0
    {
        if (1 - a * (x + a) <= 0)
        {
            cout << "log argument <= 0" << endl;
            return NAN;
            return -log(1 - a * (x + a)) / a;
        }
    }

    if (a == 0) // a==0
        return x;

    else // a>0
        return (exp(a * x) - 1) / a + a;
}

double der_SoftExponential(double a, double x)
{
    if (a < 0)
    {
        if (1 - a * (x + a) <= 0)
        {
            cout << "deerivative undefined" << endl;
            return NAN;
        }
        return 1 / (1 - a * (x + a));
    }
    else if (a == 0)
        return 1;
    else // a > 0
        return exp(a * x);
}

int main()
{
    double a, x;
    cout << "Enter a and x: ";
    cin >> a >> x;

    double y = softExponential(a, x);
    double dy = der_SoftExponential(a, x);

    cout << "y = " << y << endl;
    cout << "dy = " << dy << endl;

    return 0;
}