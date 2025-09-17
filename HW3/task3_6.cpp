#include <iostream>
using namespace std;
#include <cmath>

void task3_6(double x1, double x2, double x3)
{
    double min_num = x1;
    double max_num = x1;

    if (abs(x2) > abs(max_num))
        max_num = x2;
    if (abs(x3) > abs(max_num))
        max_num = x3;

    if (abs(x2) < abs(min_num))
        min_num = x2;
    if (abs(x3) < abs(min_num))
        min_num = x3;

    cout << "The number with the largest modulus: " << max_num << endl;
    cout << "The number with the smallest modulus: " << min_num << endl;
}

int main()
{
    double x1, x2, x3;
    cout << "Enter 3 numbers separated by a space: ";
    cin >> x1 >> x2 >> x3;

    task3_6(x1, x2, x3);
    return 0;
}