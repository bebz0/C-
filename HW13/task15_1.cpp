#include "task15_1.h"
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;

void Rational::Simplify()
{
    if (denominator == 0)
    {
        cout << "Denominator is 0. Resetting to 1/1." << endl;
        nominator = 1;
        denominator = 1;
        return;
    }
    if (denominator < 0)
    {
        nominator = -nominator;
        denominator = -denominator;
    }
    if (nominator == 0)
    {
        denominator = 1;
        return;
    }
    int g = std::gcd(abs(nominator), denominator);
    nominator /= g;
    denominator /= g;
}

Rational::Rational()
{
    nominator = 1;
    denominator = 1;
}

Rational::Rational(int nom, int den)
{
    nominator = nom;
    if (den == 0)
    {
        cout << "Denominator cannot be 0. Setting to 1." << endl;
        denominator = 1;
    }
    else
    {
        denominator = den;
    }
    Simplify();
}

void Rational::setNominator(int nom)
{
    nominator = nom;
}

void Rational::setDenominator(int den)
{
    if (den == 0)
    {
        cout << "Denominator cang be 0. Value not set" << endl;
    }
    else
    {
        denominator = den;
    }
    Simplify();
}

void Rational::input()
{
    int nom, den;
    cout << "Enter nominator: ";
    cin >> nom;
    cout << "Enter denominator: ";
    cin >> den;

    nominator = nom;
    if (den == 0)
    {
        cout << "Denominator cannot be 0. Setting to 1" << endl;
        denominator = 1;
    }
    else
    {
        denominator = den;
    }
    Simplify();
}

void Rational::output() const
{
    cout << nominator << "/" << denominator;
}

double Rational::getDouble() const
{
    return static_cast<double>(nominator) / denominator;
}

Rational Rational::operator+(const Rational &other) const
{
    int nom = nominator * other.denominator + other.nominator * denominator;
    int den = denominator * other.denominator;
    return Rational(nom, den);
}

Rational Rational::operator-(const Rational &other) const
{
    int nom = nominator * other.denominator - other.nominator * denominator;
    int den = denominator * other.denominator;
    return Rational(nom, den);
}

Rational Rational::operator*(const Rational &other) const
{
    int nom = nominator * other.nominator;
    int den = denominator * other.denominator;
    return Rational(nom, den);
}

Rational Rational::operator/(const Rational &other) const
{
    if (other.nominator == 0)
    {
        cout << "Error: Division by zero." << endl;
        return Rational(0, 1);
    }
    int nom = nominator * other.denominator;
    int den = denominator * other.nominator;
    return Rational(nom, den);
}

bool Rational::operator<(const Rational &other) const
{
    return (nominator * other.denominator < other.nominator * denominator);
}

bool Rational::operator==(const Rational &other) const
{
    return (nominator == other.nominator && denominator == other.denominator);
}

bool Rational::operator>(const Rational &other) const
{
    return (nominator * other.denominator > other.nominator * denominator);
}

bool Rational::operator!=(const Rational &other) const
{
    return !(*this == other);
}

bool Rational::operator<=(const Rational &other) const
{
    return (*this < other) || (*this == other);
}

bool Rational::operator>=(const Rational &other) const
{
    return (*this > other) || (*this == other);
}

ostream &operator<<(ostream &os, const Rational &r)
{
    os << r.nominator << "/" << r.denominator;
    return os;
}

istream &operator>>(istream &is, Rational &r)
{
    int nom;
    int den;
    char slash;

    is >> nom >> slash >> den;

    if (den == 0)
    {
        cerr << "Denominator 0 in input. Setting to 1." << endl;
        den = 1;
    }

    r.nominator = nom;
    r.denominator = den;
    r.Simplify();
    return is;
}