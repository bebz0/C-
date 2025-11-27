#include "task17_1.h"
#include <numeric>
#include <cmath>

void Rational::Simplify()
{
    if (denominator == 0)
        throw RationalException("Denominator cannot be 0.");

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
    int g = std::gcd(std::abs(nominator), denominator);
    nominator /= g;
    denominator /= g;
}

Rational::Rational() : nominator(1), denominator(1) {}

Rational::Rational(int nom, int den)
{
    if (den == 0)
        throw RationalException("Cannot initialize with denominator 0.");

    nominator = nom;
    denominator = den;
    Simplify();
}

void Rational::setNominator(int nom)
{
    nominator = nom;
    Simplify();
}

void Rational::setDenominator(int den)
{
    if (den == 0)
        throw RationalException("Attempted to set denominator to 0.");
    denominator = den;
    Simplify();
}

void Rational::input()
{
    int nom, den;
    std::cout << "Enter nominator: ";
    std::cin >> nom;
    std::cout << "Enter denominator: ";
    std::cin >> den;

    if (den == 0)
        throw RationalException("Input error: denominator = 0.");

    nominator = nom;
    denominator = den;
    Simplify();
}

void Rational::output() const
{
    std::cout << nominator << "/" << denominator;
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

Rational Rational::operator-() const
{
    return Rational(-nominator, denominator);
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
        throw RationalException("Division by zero (divisor is 0).");

    int nom = nominator * other.denominator;
    int den = denominator * other.nominator;
    return Rational(nom, den);
}

bool Rational::operator<(const Rational &other) const
{
    return nominator * other.denominator < other.nominator * denominator;
}

bool Rational::operator==(const Rational &other) const
{
    return nominator == other.nominator && denominator == other.denominator;
}

bool Rational::operator>(const Rational &other) const
{
    return !(*this <= other);
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
    return !(*this < other);
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << r.nominator << "/" << r.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Rational &r)
{
    int nom, den;
    char slash;

    if (is >> nom >> slash >> den)
    {
        if (slash != '/')
        {
            is.setstate(std::ios::failbit);
        }
        else if (den == 0)
        {
            throw RationalException("Input error: denominator cannot be 0.");
        }
        else
        {
            r.nominator = nom;
            r.denominator = den;
            r.Simplify();
        }
    }
    return is;
}

void saveToFile(const Rational &r, const std::string &filename)
{
    std::ofstream fout(filename);
    if (!fout.is_open())
        throw RationalException("Failed to open file for writing: " + filename);

    fout << r.nominator << "/" << r.denominator << std::endl;
}