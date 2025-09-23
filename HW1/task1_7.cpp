#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;
    cout << "Enter a number: ";
    cin >> x;

    // int part
    int int_part = int(x);
    cout << "Int part is: " << int_part << endl;

    int int_part_math = trunc(x);
    cout << "Int part math is: " << int_part_math << endl;

    // frac part
    double frac_part = x - int_part;
    cout << "Frac part is: " << frac_part << endl;

    double frac_part_math = fmod(x, 1.0);
    cout << "Frac part math is: " << frac_part_math << endl;

    // ceil
    int ceil_part_math = ceil(x);
    cout << "Ceil part math is: " << ceil_part_math << endl;

    int ceil_part = (x == int_part) ? int_part + 1 : (x > 0 ? int_part + 1 : int_part);
    cout << "Ceil part is: " << ceil_part << endl;

    // floor
    int floor_math_part = floor(x);
    cout << "Floor math part is: " << floor_math_part << endl;

    int floor_part = (x == int_part) ? int_part - 1 : (x > 0 ? int_part : int_part - 1);
    cout << "Floor  part is: " << floor_part << endl;

    // round
    int round_part = (x >= 0) ? int(x + 0.5) : int(x - 0.5);
    cout << "Round: " << round_part << endl;

    int round_math_part = round(x);
    cout << "Round math = " << round_math_part << endl;

    return 0;
}
