#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    int n;
    cout << "Enter x in radians: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;

    double res = x;

    for (int i = 0; i < n; ++i)
    {
        res = sin(res);
    }
    cout << "REsult: " << res << endl;
    return 0;
}