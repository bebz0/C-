#include <iostream>
#include <iomanip> //for scienfiic
using namespace std;

int main()
{
    const double Gamma = 6.673e-11;
    double m1 = 6e20;
    double m2 = 4e22;
    double r = 8e6;

    double F = Gamma * m1 * m2 / (r * r);
    cout << "F = " << scientific << setprecision(6) << F << endl;

    return 0;
}