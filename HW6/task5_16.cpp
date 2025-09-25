#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double x, eps;
    cout << "Enter x (|x| < 1): ";
    cin >> x;
    if (fabs(x) >= 1.0)
    {
        cout << "Error: |x| must be < 1.\n";
        return 1;
    }

    cout << "Enter epsilon (eps > 0): ";
    cin >> eps;
    if (eps <= 0.0)
    {
        cout << "Error: epsilon must be > 0.\n";
        return 1;
    }

    const int MAX_ITER = 100000; // lim
    double sum = 0.0;

    // k = 0
    double term = 1.0; // t0 = a0 * x^0 = 1
    int k = 0;
    int terms_count = 0;

    while (fabs(term) >= eps && k < MAX_ITER)
    {
        sum += term;
        ++terms_count;

        // term_{k+1} = term_k * ((1/2 - k) / (k+1)) * x
        double factor = (0.5 - k) / double(k + 1);
        term = term * factor * x;
        ++k;
    }

    cout << fixed << setprecision(12);
    cout << "Approximate sum = " << sum << '\n';
    cout << "Number of terms added = " << terms_count << '\n';
    cout << "Last computed term (abs) = " << fabs(term) << '\n';

    if (k >= MAX_ITER)
    {
        cout << "Warning: reached MAX_ITER`\n";
    }

    return 0;
}
