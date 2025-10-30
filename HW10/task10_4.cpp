#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

struct Rational
{
    int numerator;
    unsigned int denominator;
};

void PrintRational(const Rational &r)
{
    if (r.denominator == 0)
    {
        cout << "Invalid Rational (division by zero)";
        return;
    }
    cout << r.numerator << "/" << r.denominator;
}

void Reduce(Rational &r)
{
    if (r.denominator == 0)
    {
        cout << "Denominator can't be zero\n";
        return;
    }

    if (r.numerator == 0)
    {
        r.denominator = 1;
        return;
    }

    int common_div = gcd(r.numerator, r.denominator);

    r.numerator /= common_div;
    r.denominator /= common_div;
}

Rational Add(const Rational &r1, const Rational &r2)
{
    Rational result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    Reduce(result);
    return result;
}

Rational Multiply(const Rational &r1, const Rational &r2)
{
    Rational result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    Reduce(result);
    return result;
}

int Compare(const Rational &r1, const Rational &r2)
{
    long val1 = (r1.numerator) * r2.denominator;
    long val2 = (r2.numerator) * r1.denominator;

    if (val1 > val2)
        return 1;
    if (val1 < val2)
        return -1;
    return 0;
}

int main()
{
    Rational a = {1, 2};
    Rational b = {3, 4};
    cout << "Number a: ";
    PrintRational(a);
    cout << "\n\n";

    cout << "Number b: ";
    PrintRational(b);
    cout << "\n\n";

    cout << "Sum a + b:\n";
    Rational sum = Add(a, b);
    PrintRational(a);

    cout << " + ";
    PrintRational(b);
    cout << " = ";
    PrintRational(sum);
    cout << "\n\n";

    cout << "Dot a * b:\n";
    Rational product = Multiply(a, b);
    PrintRational(a);

    cout << " * ";
    PrintRational(b);
    cout << " = ";
    PrintRational(product);
    cout << "\n\n";

    cout << "Reduce:\n";
    Rational c = {12, 18};

    cout << "Before: ";
    PrintRational(c);
    Reduce(c);
    cout << "\t";

    cout << "After: ";
    PrintRational(c);
    cout << "\n\n";

    cout << "Compare a and b:\n";
    int comparison_result = Compare(a, b);
    PrintRational(a);
    if (comparison_result < 0)
        cout << " < ";
    else if (comparison_result > 0)
        cout << " > ";
    else
        cout << " == ";
    PrintRational(b);

    return 0;
}