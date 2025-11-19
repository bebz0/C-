#include <iostream>
#include <cmath>
#include <iomanip>
#include "task15_1.h"

using namespace std;

void findSmallestRational()
{
    cout << "\nTask 1" << endl;
    int n;
    cout << "Enter number of elements (n): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n must be >0" << endl;
        return;
    }

    Rational *arr = new Rational[n];

    cout << "Enter " << n << " rational numbers (in a/b format):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    Rational minVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }

    cout << "\nThe smallest rational number is: " << minVal << endl;

    delete[] arr;
}

void calculateSeries()
{
    cout << "\nTask 2" << endl;
    double precision = 0.01;
    Rational sum(0, 1);
    Rational term;
    int k = 1;

    do
    {
        int sign = (k % 2 == 1) ? 1 : -1;
        int nom = sign;
        int den = k * k;

        term = Rational(nom, den);
        sum = sum + term;

        k++;

    } while (abs(term.getDouble()) > precision);

    double pi_sq_12 = (M_PI * M_PI) / 12.0;

    cout << "Series: 1 - 1/4 + 1/9 - 1/16 + ..." << endl;
    cout << "Precision (term > 0.01): " << precision << endl;
    cout << "Number of iterations: " << (k - 1) << endl;

    cout << "\nCalculated sum (as rational): " << sum << endl;
    cout << "Calculated sum (as double):   " << fixed << setprecision(10) << sum.getDouble() << endl;
    cout << "Expected value (pi^2 / 12): " << fixed << setprecision(10) << pi_sq_12 << endl;

    if (abs(sum.getDouble() - pi_sq_12) < precision)
    {
        cout << "Res: The sum converges" << endl;
    }
    else
    {
        cout << "Result: The sum doesn't converge" << endl;
    }
}

int main()
{
    findSmallestRational();
    calculateSeries();
    return 0;
}