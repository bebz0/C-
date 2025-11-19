#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex() : re(0), im(0) {}
    Complex(double r, double i) : re(r), im(i) {}

    double abs() const
    {
        return std::sqrt(re * re + im * im);
    }

    Complex operator+(const Complex &other) const
    {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex &other) const
    {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator-() const { return Complex(-re, -im); }

    Complex operator*(const Complex &other) const
    {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Complex operator/(double scalar) const
    {
        if (scalar == 0)
            throw runtime_error("Division by zero");
        return Complex(re / scalar, im / scalar);
    }

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << "(" << c.re << (c.im >= 0 ? "+" : "") << c.im << "i)";
        return os;
    }

    friend istream &operator>>(istream &is, Complex &c)
    {
        cout << "  Real: ";
        is >> c.re;
        cout << "  Imag: ";
        is >> c.im;
        return is;
    }
};

void clearInputStream()
{
    cin.clear();
    while (cin.get() != '\n')
        ;
}

Complex calculateArctg(const Complex &z, double epsilon)
{
    if (epsilon < 0)
    {
        throw logic_error("Program state error: Epsilon cannot be negative.");
    }

    if (z.abs() >= 1.0)
    {
        throw domain_error("Convergence error: |z| must be < 1.");
    }

    Complex sum(0, 0);
    Complex z_pow = z;
    Complex z_sq = z * z;
    int n = 0;

    int capacity = 10;
    int size = 0;
    Complex *history = new Complex[capacity];

    try
    {
        while (true)
        {
            double divisor = 2 * n + 1;
            Complex term = z_pow / divisor;

            if (n % 2 != 0)
                term = -term;

            if (term.abs() < epsilon)
                break;

            if (size >= capacity)
            {
                capacity *= 2;
                Complex *new_history = new Complex[capacity];

                for (int i = 0; i < size; ++i)
                {
                    new_history[i] = history[i];
                }

                delete[] history;
                history = new_history;
            }

            history[size] = term;
            size++;

            sum = sum + term;

            z_pow = z_pow * z_sq;
            n++;

            if (n > 100000)
                throw runtime_error("Too many iterations.");
        }
    }
    catch (...)
    {
        delete[] history;
        throw;
    }

    delete[] history;
    return sum;
}

int main()
{
    while (true)
    {
        try
        {
            Complex z;
            double eps;
            int choice;

            cout << "\n--- Arctg(z) Calculator ---" << endl;
            cout << "Enter complex number z:" << endl;

            if (!(cin >> z))
            {
                throw invalid_argument("Invalid input for complex number.");
            }

            cout << "Enter epsilon (precision): ";
            if (!(cin >> eps))
            {
                throw invalid_argument("Invalid input for epsilon.");
            }

            Complex result = calculateArctg(z, eps);
            cout << "Result: arctg" << z << " = " << result << endl;
        }
        catch (const domain_error &e)
        {
            cout << "Math Error: " << e.what() << endl;
        }
        catch (const invalid_argument &e)
        {
            cout << "Input Error: " << e.what() << endl;
            clearInputStream();
        }
        catch (const bad_alloc &e)
        {
            cout << "Memory Error: Allocation failed! " << e.what() << endl;
            return 1;
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }

        cout << "\nContinue? (1-Yes, 0-No): ";
        int c;
        cin >> c;
        if (c == 0)
            break;
        clearInputStream();
    }

    return 0;
}