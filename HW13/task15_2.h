#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;
    static int instanceCount;

public:
    Point();
    Point(double x, double y);

    void input();
    double getX() const;
    double getY() const;

    double distance(const Point &other) const;

    static int counter();
};