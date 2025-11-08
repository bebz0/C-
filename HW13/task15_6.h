#pragma once
#include <iostream>

using namespace std;

class Rectangle
{
private:
    double x;
    double y;
    double width;
    double height;

public:
    Rectangle(double x, double y, double width, double height);

    double getWidth() const;
    double getHeight() const;

    double getLeft() const;
    double getRight() const;
    double getTop() const;
    double getBottom() const;

    double getArea() const;
    double getPerimeter() const;

    Rectangle getIntersection(const Rectangle &other) const;

    void display() const;
};