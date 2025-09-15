#include <iostream>
using namespace std;

int main()
{
    double x = 2;

    // x^4
    // 1) x^2 = x * x
    // 2) x^4 = x^2 * x^2
    double x2 = x * x;
    double x4 = x2 * x2;

    // x^6
    // 1)x^2 = x * x
    // 2)x^4 = x^2 * x^2
    // 3)x^6 = x^4 * x^2
    double x6 = x4 * x2;

    // x^9
    // 1)x^2 = x * x
    // 2)x^4 = x^2 * x^2
    // 3)x^8 = x^4 * x^4
    // 4)x^9 = x^8 * x
    double x8 = x4 * x4;
    double x9 = x8 * x;

    // x^15
    // 1)x^2 = x * x
    // 2)x^3 = x^2 * x
    // 3)x^6 = x^3 * x^3
    // 4)x^12 = x^6 * x^6
    // 5)x^15 = x^12 * x^3
    double x3 = x2 * x;
    double x12 = x6 * x6;
    double x15 = x12 * x3;

    // x^28
    // 1)x^2 = x * x
    // 2)x^4 = x^2 * x^2
    // 3)x^8 = x^4 * x^4
    // 4)x^12 = x^8 * x^4
    // 5)x^24 = x^12 * x^12
    // 6)x^28 = x^24 * x^4
    double x24 = x12 * x12;
    double x28 = x24 * x4;

    // x^64
    // 1)x^2 = x * x
    // 2)x^4 = x^2 * x^2
    // 3)x^8 = x^4 * x^4
    // 4)x^16 = x^8 * x^8
    // 5)x^32 = x^16 * x^16
    // 6)x^64 = x^32 * x^32
    double x16 = x8 * x8;
    double x32 = x16 * x16;
    double x64 = x32 * x32;

    // output

    cout << "x^4   = " << x4 << "\n";
    cout << "x^6   = " << x6 << "\n";
    cout << "x^9   = " << x9 << "\n";
    cout << "x^15  = " << x15 << "\n";
    cout << "x^28  = " << x28 << "\n";
    cout << "x^64  = " << x64 << "\n";

    return 0;
}
