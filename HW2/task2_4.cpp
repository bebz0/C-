#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    double x;
    cout << "Enter the x: ";
    if (!(cin >> x))
        return 0;

    double x2;
    cout << "Enter the x2: ";
    if (!(cin >> x2))
        return 0;

    double y = (1 - pow((2 * x), 5)) / (1 - 2 * x); // expression 16x^4 + 8x^3 + 4x^2 + 2x + 1
    cout << "Expression 16x^4 + 8x^3 + 4x^2 + 2x + 1 = " << y << endl;

    // expression x^5 + 5x^4 + 10x^3 + 10x^2 + 5x + 1
    double t = x2 + 1.0; //(x + 1)
    double t2 = t * t;   //(x + 1)^2
    double t4 = t2 * t2; // (x + 1)^4
    double y2 = t4 * t;  // (x + 1)^5

    cout << "Expression x^5 + 5x^4 + 10x^3 + 10x^2 + 5x + 1 = " << y2 << endl;
    return 0;
}