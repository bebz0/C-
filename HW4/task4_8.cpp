#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m;
    cout << "Enter the m: ";
    cin >> m;

    if (m < 1)
    {
        cout << "m must be >= 1";
        return 1;
    }

    int k;
    int power = 1;

    for (k = 0; power * 4 <= m; k++)
    {
        power *= 4;
    }

    cout << "K = " << k << endl;
    return 0;
}
