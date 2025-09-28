#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

double my_exp(double x, double epsilon)
{
    double sum = 1.0;  // the first term of the series
    double term = 1.0; // current tern of the series
    int n = 1;

    while (fabs(term) >= epsilon)
    {
        term *= x / n; // x^n / n! = (x^(n-1)/(n-1)!) * (x/n)
        sum += term;
        n++;

        if (n > 1000) // just a lim
            break;
    }

    return sum;
}

double my_phi(double x, double epsilon)
{
    double sum = x;  // the first term of the series
    double term = x; // current tern of the series
    int n = 1;
    int sign = -1; // sign

    while (fabs(term) >= epsilon)
    {
        // (-1)^n * x^(2n+1) / ((2n+1) * (2n-1)!!)
        // term * (-x^2) / (2n * (2n+1))
        term *= (-x * x) / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;

        if (n > 1000)
            break;
    }

    return sum;
}

int main()
{
    double epsilon;
    double x;

    cout << "Enter  epsilon: ";
    cin >> epsilon;

    cout << "Enter x: ";
    cin >> x;

    double my_exp_result = my_exp(x, epsilon);

    cout << "\na)e^x:" << endl;
    cout << "Func: e^" << x << " = " << my_exp_result << endl;
    cout << "Math func: " << exp(x) << endl;
    cout << "Dif: " << fabs(my_exp_result - exp(x)) << endl;
    cout << "Acurracy: " << epsilon << endl;

    double my_phi_result = my_phi(x, epsilon);
    // erf(x) = 2/√π * Φ(x√π/2)
    // F(x) = (√π/2) * erf(x)
    double math_phi = (sqrt(M_PI) / 2) * erf(x);

    cout << "\nb)F(x) = ∫₀^x e^(-t²) dt:" << endl;
    cout << "My func: F(" << x << ") = " << my_phi_result << endl;
    cout << "Math func: " << math_phi << endl;
    cout << "Dif: " << fabs(my_phi_result - math_phi) << endl;
    cout << "Acuraccy" << epsilon << endl;
}