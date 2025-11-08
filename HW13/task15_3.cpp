#include "task15_3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

Polynomial::Polynomial(int n)
{
    size = n;
    coeff = new double[size];
    for (int i = 0; i < size; ++i)
    {
        coeff[i] = 0.0;
    }
}

Polynomial::Polynomial(int n, double *data)
{
    size = n;
    coeff = new double[size];
    for (int i = 0; i < size; ++i)
    {
        coeff[i] = data[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] coeff;
}

Polynomial::Polynomial(const Polynomial &other)
{
    size = other.size;
    coeff = new double[size];
    for (int i = 0; i < size; ++i)
    {
        coeff[i] = other.coeff[i];
    }
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] coeff;

    size = other.size;
    coeff = new double[size];
    for (int i = 0; i < size; ++i)
    {
        coeff[i] = other.coeff[i];
    }
    return *this;
}

void Polynomial::setcoeff(double *data)
{
    for (int i = 0; i < size; ++i)
    {
        coeff[i] = data[i];
    }
}

void Polynomial::setCoefficient(int index, double value)
{
    if (index >= 0 && index < size)
    {
        coeff[index] = value;
    }
    else
    {
        cout << "Index out of range" << endl;
    }
}

void Polynomial::display() const
{
    cout << "P(x) = ";
    for (int i = 0; i < size; ++i)
    {
        if (coeff[i] != 0)
        {
            if (i != 0)
            {
                cout << (coeff[i] > 0 ? " + " : " - ");
            }
            cout << abs(coeff[i]);
            if (i > 0)
            {
                cout << "x^" << i;
            }
        }
    }
    cout << endl;
}

int Polynomial::getSize() const
{
    return size;
}

bool saveToBinary(const Polynomial &p, const string &filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Cant open file for writing" << endl;
        return false;
    }

    file.write((char *)&p.size, sizeof(p.size));
    file.write((char *)p.coeff, p.size * sizeof(double));

    file.close();
    return true;
}

Polynomial loadFromBinary(const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        throw runtime_error("Can't open file for reading");
    }

    int n;
    file.read((char *)&n, sizeof(n));

    if (n <= 0)
    {
        throw runtime_error("Invalid size read from file");
    }

    Polynomial p(n);
    file.read((char *)p.coeff, n * sizeof(double));

    file.close();
    return p;
}