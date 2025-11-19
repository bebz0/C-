#include "task15_2.h"
#include <iostream>
#include <cmath>

using namespace std;
int Point::instanceCount = 0;

Point::Point()
{
    x = 0.0;
    y = 0.0;
    instanceCount++;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
    instanceCount++;
}

void Point::input()
{
    cout << "  Enter x: ";
    cin >> x;
    cout << "  Enter y: ";
    cin >> y;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::distance(const Point &other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    return hypot(dx, dy);
}

int Point::counter()
{
    return instanceCount;
}