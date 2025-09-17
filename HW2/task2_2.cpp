#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double b;
    cin >> a >> b;
    double c = sqrt(a * a + b * b);
    cout << "Hypotenuse = " << c << endl;
}