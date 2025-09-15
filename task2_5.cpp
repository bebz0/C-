#include <iostream>
#include <cmath>
using namespace std;

double Rosenbrock2d(double x, double y)
{
    return (100 * pow((x * x - y), 2) + pow((x - 1), 2));
}

int main()
{
    double x, y;
    cin >> x >> y;

    double a, b;
    cin >> a >> b;

    double c, d;
    cin >> c >> d;

    cout << "1 result = " << Rosenbrock2d(x, y) << endl;
    cout << "2 result = " << Rosenbrock2d(a, b) << endl;
    cout << "3 result = " << Rosenbrock2d(c, d) << endl;
}