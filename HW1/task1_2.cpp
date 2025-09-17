#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    cout << fixed << setprecision(2); // 2 decimal places

    // 10^-4 = 0.0001
    float a = 1e-4f;
    double a_doub = 1e-4;
    long double a_ldoub = 1e-4L;

    cout << "10^-4\n";
    cout << "float:       " << a << "\n";
    cout << "double:      " << a_doub << "\n";
    cout << "long double: " << a_ldoub << "\n\n";

    // 24.33E5 = 2433000
    float b = 24.33e5f;
    double b_doub = 24.33e5;
    long double b_ldoub = 24.33e5L;

    cout << "24.33E5\n";
    cout << "float:       " << b << "\n";
    cout << "double:      " << b_doub << "\n";
    cout << "long double: " << b_ldoub << "\n\n";

    // π = 3.14
    float c = static_cast<float>(M_PI);
    double c_doub = M_PI;
    long double c_ldoub = M_PI;

    cout << "pi\n";
    cout << "float:       " << c << "\n";
    cout << "double:      " << c_doub << "\n";
    cout << "long double: " << c_ldoub << "\n\n";

    // e = 2.72
    float d = static_cast<float>(M_E);
    double d_doub = M_E;
    long double d_ldoub = M_E;

    cout << "e\n";
    cout << "float:       " << d << "\n";
    cout << "double:      " << d_doub << "\n";
    cout << "long double: " << d_ldoub << "\n\n";

    // sqrt(5) = 2.24
    float e = sqrtf(5.0f);
    double e_doub = sqrt(5.0);
    long double e_ldoub = sqrt((long double)5.0);

    cout << "sqrt(5)\n";
    cout << "float:       " << e << "\n";
    cout << "double:      " << e_doub << "\n";
    cout << "long double: " << e_ldoub << "\n\n";

    // ln(100) = 4.61
    float f = logf(100.0f);
    double f_doub = log(100.0);
    long double f_ldoub = log((long double)100.0);

    cout << "ln(100)\n";
    cout << "float:       " << f << "\n";
    cout << "double:      " << f_doub << "\n";
    cout << "long double: " << f_ldoub << "\n\n";

    return 0;
}
