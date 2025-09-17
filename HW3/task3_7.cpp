#include <iostream>
#include <cmath>
using namespace std;

void quadratic(double a, double b, double c)
{
    if (a == 0)
    {
        if (b != 0)
            cout << "One root: x = " << -c / b << endl;
        else
            cout << (c == 0 ? "Infinite solutions" : "No real roots") << endl;
        return;
    }
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        cout << "No real roots" << endl;
        return;
    }
    double x1 = (-b + sqrt(D)) / (2 * a), x2 = (-b - sqrt(D)) / (2 * a);
    if (D == 0)
        cout << "One root: x = " << x1 << endl;
    else
        cout << "Two roots: x1 = " << x1 << ", x2 = " << x2 << endl;
}

void biquadratic(double a, double b, double c)
{

    if (a == 0)
    {
        quadratic(b, 0, c);
        return;
    }
    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        cout << "No real roots" << endl;
        return;
    }

    double y1 = (-b + sqrt(D)) / (2 * a), y2 = (-b - sqrt(D)) / (2 * a);
    for (double y : {y1, y2})
    {
        if (y > 0)
            cout << "Roots: x = " << sqrt(y) << ", x = " << -sqrt(y) << endl;
        else if (y == 0)
            cout << "Root: x = 0" << endl;
    }
}

int main()
{
    double a, b, c;
    cout << "Enter a, b, c for ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;
    quadratic(a, b, c);

    cout << "\nEnter a, b, c for ax^4 + bx^2 + c = 0: ";
    cin >> a >> b >> c;
    biquadratic(a, b, c);

    return 0;
}
