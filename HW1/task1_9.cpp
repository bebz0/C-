#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    double sum_arith = a + b;
    double prod_arith = a * b;

    // H = 2ab / (a+b)
    double sum_harm = 2 * a * b / (a + b);
    double prod_harm = sum_harm;

    cout << fixed << setprecision(3);
    cout << "Arithmetic mean (decimal) = " << sum_arith << ", product = " << prod_arith << endl;

    cout << scientific << setprecision(3);
    cout << "Arithmetic mean (scientific) = " << sum_arith << ", product = " << prod_arith << endl;

    cout << fixed << setprecision(3);
    cout << "Harmonic mean (decimal) = " << sum_harm << ", product = " << prod_harm << endl;

    cout << scientific << setprecision(3);
    cout << "Harmonic mean (scientific) = " << sum_harm << ", product = " << prod_harm << endl;

    return 0;
}
