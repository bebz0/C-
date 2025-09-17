#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double area_by_sides(double a, double b, double c)
{
    double p = (a + b + c) / 2.0;
    double prod = p * (p - a) * (p - b) * (p - c);
    return (prod > 0.0) ? sqrt(prod) : 0.0;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter the coordinates of A (x y): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of B (x y): ";
    cin >> x2 >> y2;

    cout << "Enter the coordinates of C (x y): ";
    cin >> x3 >> y3;

    double a = dist(x2, y2, x3, y3); // BC
    double b = dist(x1, y1, x3, y3); // AC
    double c = dist(x1, y1, x2, y2); // AB

    double area = area_by_sides(a, b, c);

    cout << fixed << setprecision(6);
    cout << "Sides : a=" << a << ", b=" << b << ", c=" << c << '\n';
    cout << "Area: S = " << area << '\n';

    return 0;
}