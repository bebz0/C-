#pragma once
#include <iostream>

using namespace std;
class Interval
{
private:
    double left;
    double right;
    bool leftIncluded;
    bool rightIncluded;

    bool contains(double p) const;

public:
    Interval();
    Interval(double l, double r, bool li, bool ri);

    double getLeft() const;
    double getRight() const;
    bool isEmpty() const;

    void input();
    void display() const;

    Interval getIntersection(const Interval &other) const;
    Interval getUnion(const Interval &other) const;
};