#include "task15_6.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangle::Rectangle(double x, double y, double width, double height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getHeight() const
{
    return height;
}

double Rectangle::getLeft() const
{
    return x;
}

double Rectangle::getRight() const
{
    return x + width;
}

double Rectangle::getTop() const
{
    return y;
}

double Rectangle::getBottom() const
{
    return y - height;
}

double Rectangle::getArea() const
{
    return width * height;
}

double Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}

Rectangle Rectangle::getIntersection(const Rectangle &other) const
{
    double intersectLeft = (this->getLeft() > other.getLeft())
                               ? this->getLeft()
                               : other.getLeft();
    double intersectTop = (this->getTop() < other.getTop())
                              ? this->getTop()
                              : other.getTop();
    double intersectRight = (this->getRight() < other.getRight())
                                ? this->getRight()
                                : other.getRight();
    double intersectBottom = (this->getBottom() > other.getBottom())
                                 ? this->getBottom()
                                 : other.getBottom();

    double intersectWidth = intersectRight - intersectLeft;
    double intersectHeight = intersectTop - intersectBottom;
    if (intersectWidth <= 0 || intersectHeight <= 0)
    {
        return Rectangle(-1, -1, -1, -1);
    }

    return Rectangle(intersectLeft, intersectTop, intersectWidth, intersectHeight);
}

void Rectangle::display() const
{
    cout << "Rect[x=" << x << ", y=" << y << ", w=" << width << ", h=" << height << "]" << endl;
}