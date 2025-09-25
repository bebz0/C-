#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter x: ";
    cin >> x;

    // First statement
    bool y1 = ((x & (x - 1)) > 0);

    // Second dtatement
    int y2 = x & (-x);

    cout << "x = " << x << endl;
    cout << "((x & (x - 1)) > 0) = " << y1 << endl;
    cout << "(x & -x) = " << y2 << endl;

    // Additional property check
    if ((x & (x - 1)) == 0)
        cout << "x is a power of two" << endl;
    else
        cout << "x is not a power of two" << endl;

    return 0;
}
