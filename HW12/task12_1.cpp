#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, y;
    cout << "Enter x = ";
    cin >> x;
    cout << "Enter y = ";
    cin >> y;

    double res = pow(x, y);
    cout << setprecision(6);
    cout << "Result (decimal): " << fixed << res << endl;
    cout << "Result (scientific): " << scientific << res << endl;
    return 0;
}