#include <iostream>
using namespace std;

int main()
{
    double x, y;
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;

    double sum = x + y;
    double product = x * y;

    cout << "Sum:    " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}