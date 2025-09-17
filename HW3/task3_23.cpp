#include <iostream>
#include <cmath>
#include <limits> // for inf

using namespace std;

// Soft Exponential
double softExponential(double a, double x)
{
    if (a < 0) // a < 0
    {
        double arg = 1 - a * (x + a);
        if (arg < 0) // log argument cannot be negative
        {
            cout << "log argument < 0,  undefined" << endl;
            return NAN;
        }
        if (fabs(arg) < 1e-15) // argument too close to zero
        {
            cout << "function -> max double" << endl;
            return numeric_limits<double>::max();
        }
        return -log(arg) / a;
    }
    else if (a == 0) // a = 0
    {
        return x;
    }
    else // a > 0
    {
        double val = (exp(a * x) - 1) / a + a;
        // if overflw
        if (val > numeric_limits<double>::max())
        {
            cout << "function -> max double" << endl;
            return numeric_limits<double>::max();
        }
        return val;
    }
}

// Der of Soft Exponential
double der_SoftExponential(double a, double x)
{
    if (a < 0) // a < 0
    {
        double denom = 1 - a * (x + a);
        if (fabs(denom) < 1e-15) // denom close to zero
        {
            cout << "derivative -> max double" << endl;
            return numeric_limits<double>::max();
        }
        if (denom < 0) // undefined for negative denom
        {
            cout << "derivative undefinedd" << endl;
            return NAN;
        }
        return 1.0 / denom;
    }
    else if (a == 0) // a = 0
    {
        return 1.0;
    }
    else // case a > 0
    {
        double val = exp(a * x);
        //  overflow
        if (val > numeric_limits<double>::max())
        {
            cout << "derivative -> max double" << endl;
            return numeric_limits<double>::max();
        }
        return val;
    }
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
