#pragma once
#include <iostream>
#include <fstream>
#include "Rational_exception.h"

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

    // арифметичні оператори
    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const; // двійкове віднімання
    Rational operator-() const;                      // унарне віднімання
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;

    // порівняння
    bool operator<(const Rational &other) const;
    bool operator==(const Rational &other) const;
    bool operator>(const Rational &other) const;
    bool operator!=(const Rational &other) const;
    bool operator<=(const Rational &other) const;
    bool operator>=(const Rational &other) const;

    // потокові оператори
    friend std::ostream &operator<<(std::ostream &os, const Rational &r);
    friend std::istream &operator>>(std::istream &is, Rational &r);

    // дружня функція запису у файл
    friend void saveToFile(const Rational &r, const std::string &filename);
};
