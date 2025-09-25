#include <iostream>
using namespace std;

int main()
{
    int x1 = -99, x2 = -99, x3 = -99;
    int n = 3;
    int xn;

    while (true)
    {
        xn = x3 + x1 + 100;
        n++;
        if (xn > 0)
        {
            cout << "Smallest positive number: " << xn << ", its n = " << n << endl;
            break;
        }
        x1 = x2;
        x2 = x3;
        x3 = xn;
    }

    return 0;
}
