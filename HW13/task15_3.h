#pragma once
#include <iostream>
#include <string>

using namespace std;

class Polynomial
{
private:
    double *coeff;
    int size;

public:
    Polynomial(int n);
    Polynomial(int n, double *data);
    ~Polynomial();
    Polynomial(const Polynomial &other);
    Polynomial &operator=(const Polynomial &other);

    void setcoeff(double *data);
    void setCoefficient(int index, double value);
    void display() const;
    int getSize() const;

    friend bool saveToBinary(const Polynomial &p, const string &filename);
    friend Polynomial loadFromBinary(const string &filename);
};