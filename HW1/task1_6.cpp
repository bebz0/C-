#include <iostream>
using namespace std;

int main()
{
    double C;
    cout << "Enter the number of degrees Celsius: ";
    cin >> C;

    double F = (9 * C) / 5 + 32;
    cout << "F = " << F << endl;

    return 0;
}