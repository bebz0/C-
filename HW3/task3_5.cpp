#include <iostream>
using namespace std;

void task3_5(double a, double b)
{
    int min_num, max_num;
    if (a < b)
    {
        min_num = a;
        max_num = b;
    }
    else
    {
        min_num = b;
        max_num = a;
    }

    cout << "min:" << min_num << endl;
    cout << "max:" << max_num << endl;
}

int main()
{
    double a, b;
    cout << "Enter two numbers separated by a space: ";
    cin >> a >> b;
    task3_5(a, b);
    return 0;
}