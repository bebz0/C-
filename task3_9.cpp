#include <iostream>
using namespace std;

int main()
{
    double x, y, z;
    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    // a) max(x + y + z, xy - xz + yz, xyz)
    double exp1 = x + y + z;             // x+y+z
    double exp2 = x * y - x * z + y * z; // xy-xz + yz
    double exp3 = x * y * z;             // xyz
    double max_a = exp1;                 // max

    if (exp2 > max_a)
        max_a = exp2;
    if (exp3 > max_a)
        max_a = exp3;

    cout << "a) Maximum: " << max_a << endl;

    // b) max(xy, xz, yz)
    double temp1 = x * y; // xy
    double temp2 = x * z; // xz
    double temp3 = y * z; // yz
    double max_b = temp1; // max

    if (temp2 > max_b)
        max_b = temp2;
    if (temp3 > max_b)
        max_b = temp3;

    cout << "b) Maximum: " << max_b << endl;

    return 0;
}
