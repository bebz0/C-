#include "task15_17.h"
#include <iostream>

using namespace std;
Interval::Interval()
{
    left = 0;
    right = -1;
    leftIncluded = false;
    rightIncluded = false;
}

Interval::Interval(double l, double r, bool li, bool ri)
{
    left = l;
    right = r;
    leftIncluded = li;
    rightIncluded = ri;

    if (left > right)
    {
        left = 0;
        right = -1;
        leftIncluded = false;
        rightIncluded = false;
    }
}

double Interval::getLeft() const
{
    return left;
}

double Interval::getRight() const
{
    return right;
}

bool Interval::isEmpty() const
{
    if (left > right)
        return true;
    if (left == right && (!leftIncluded || !rightIncluded))
        return true;
    return false;
}

bool Interval::contains(double p) const
{
    if (p < left || p > right)
        return false;
    if (p == left && !leftIncluded)
        return false;
    if (p == right && !rightIncluded)
        return false;
    return true;
}

void Interval::input()
{
    char c1, comma, c2;
    cout << "Enter interval: ";
    cin >> c1 >> left >> comma >> right >> c2;
    leftIncluded = (c1 == '[');
    rightIncluded = (c2 == ']');

    if (left > right)
    {
        left = 0;
        right = -1;
        leftIncluded = false;
        rightIncluded = false;
    }
}

void Interval::display() const
{
    if (isEmpty())
    {
        cout << "(empty)";
        return;
    }
    cout << (leftIncluded ? "[" : "(") << left << "," << right << (rightIncluded ? "]" : ")");
}

Interval Interval::getIntersection(const Interval &other) const
{
    double i_left = (this->left > other.left) ? this->left : other.left;
    double i_right = (this->right < other.right) ? this->right : other.right;

    if (i_left > i_right)
    {
        return Interval(0, -1, false, false);
    }

    bool i_left_inc = this->contains(i_left) && other.contains(i_left);
    bool i_right_inc = this->contains(i_right) && other.contains(i_right);

    if (i_left == i_right && (!i_left_inc || !i_right_inc))
    {
        return Interval(0, -1, false, false);
    }

    return Interval(i_left, i_right, i_left_inc, i_right_inc);
}

Interval Interval::getUnion(const Interval &other) const
{
    bool overlaps = !this->getIntersection(other).isEmpty();
    bool touches = (this->right == other.left && (this->rightIncluded || other.leftIncluded)) ||
                   (this->left == other.right && (this->leftIncluded || other.rightIncluded));

    if (!overlaps && !touches)
    {
        return Interval(0, -1, false, false);
    }

    double u_left = (this->left < other.left) ? this->left : other.left;
    double u_right = (this->right > other.right) ? this->right : other.right;

    bool u_left_inc = (this->left < other.left) ? this->leftIncluded : (other.left < this->left ? other.leftIncluded : (this->leftIncluded || other.leftIncluded));

    bool u_right_inc = (this->right > other.right) ? this->rightIncluded : (other.right > this->right ? other.rightIncluded : (this->rightIncluded || other.rightIncluded));

    return Interval(u_left, u_right, u_left_inc, u_right_inc);
}