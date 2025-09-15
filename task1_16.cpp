#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// F(x) = e^{-x^2}
double f1(double x)
{
    return exp(-x * x);
}

// F(x) = sqrt(x)
double f2(double x)
{
    return sqrt(x);
}

int main()
{
    cout << "Table for F(x) = e^(-x^2):" << endl;
    cout << "x----|-1-|-2-|-3-|-4-|-5-|" << endl;
    cout << "------|---|---|---|---|---|" << endl;
    cout << "F(x)|";

    for (int x = 1; x <= 5; x++)
    {
        double result = exp(-x * x);
        if (result < 0.005) // If the value is small
        {
            cout << "-0-|";
        }
        else if (result == floor(result))
        {
            // whole num
            cout << "-" << (int)result << "-|";
        }
        else if (result < 1)
        {
            // integer less than 1
            cout << fixed << setprecision(2) << result << "|";
        }
        else
        {
            // More than 1
            cout << fixed << setprecision(1) << result << "|";
        }
    }
    cout << endl
         << endl;

    cout << "F(x) = sqrt(x):" << endl;
    cout << "x----|-1-|-2-|-3-|-4-|-5-|" << endl;
    cout << "------|---|---|---|---|---|" << endl;
    cout << "F(x)|";

    for (int x = 1; x <= 5; x++)
    {
        double result = sqrt(x);
        if (result == floor(result))
        {
            // whole num
            cout << "-" << (int)result << "-|";
        }
        else
        {
            // Integer
            cout << fixed << setprecision(2) << result << "|";
        }
    }
    cout << endl;

    return 0;
}
