#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int colWidth = 4;

void printLine(int n, int colWidth)
{
    cout << "+";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < colWidth; ++j)
        {
            cout << "-";
        }
        cout << "+";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n must be >0" << endl;
        return 1;
    }

    printLine(n, colWidth);
    for (int i = 1; i <= n; ++i)
    {
        cout << " " << setw(colWidth) << right << i;
    }
    cout << endl;
    printLine(n, colWidth);
    cout << fixed;
    for (int i = 1; i <= n; ++i)
    {
        double root = sqrt(static_cast<double>(i));
        long long int_root = static_cast<long long>(root);
        cout << " ";
        if (int_root * int_root == i)
        {
            cout << setprecision(0) << setw(colWidth) << right << root;
        }
        else
        {
            cout << setprecision(2) << setw(colWidth) << right << root;
        }
    }
    cout << endl;
    printLine(n, colWidth);
    return 0;
}