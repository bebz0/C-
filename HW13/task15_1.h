#pragma once
#include <iostream>

using namespace std;

class Rational
{
private:
    int nominator;
    int denominator;
    void Simplify();

public:
    Rational();
    Rational(int nom, int den);

    void setNominator(int nom);
    void setDenominator(int den);

    void input();
    void output() const;
    double getDouble() const;

    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;

    bool operator<(const Rational &other) const;
    bool operator==(const Rational &other) const;
    bool operator>(const Rational &other) const;
    bool operator!=(const Rational &other) const;
    bool operator<=(const Rational &other) const;
    bool operator>=(const Rational &other) const;

    friend ostream &operator<<(ostream &os, const Rational &r);
    friend istream &operator>>(istream &is, Rational &r);
};