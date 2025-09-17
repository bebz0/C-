#include <iostream>
#include <cmath>

using namespace std;

double func_2(double x, double y)
{
    double res = 0;
    double t1 = x * x * y * y; // x^2*y^2
    double t2 = t1 * x * y;    // x^3*y^3
    double t3 = t1 * t1;       // x^4*y^4

    res = t1 + t2 + t3;
    return res;
}

double func_3(double x, double y)
{
    double res = 0;
    double a1 = x * x;   // x^2
    double b1 = y * y;   // y^2
    double a2 = a1 * x;  // x^3
    double b2 = b1 * y;  // y^3
    double a3 = a1 * a1; // x^4
    double b3 = b1 * b1; // y^4

    res = x + y + a1 + b1 + a2 + b2 + a3 + b3;
    return res;
}

int main()
{
    double x, y;
    cout << "Enter x and y separated by a space: ";
    cin >> x >> y;

    cout << "Expression 2: " << func_2(x, y) << endl;
    cout << "Expression 3: " << func_3(x, y) << endl;
    return 0;
}