#include <iostream>
#include <cmath>

using namespace std;

long long func1(int x, int n)
{
    long long y = 0;
    long long xi = 1;
    for (int i = 0; i <= n; i++)
    {
        y += xi;
        xi *= x;
    }
    return y;
}

long long func2(int n, int x, int y)
{
    long long sum = 1;
    for (int i = 1; i <= n; ++i)
    {
        int exp = (int)pow(2, i);
        long long term = (long long)pow(x, exp) * (long long)pow(y, i);
        sum += term;
    }
    return sum;
}

int main()
{
    int n1 = 3;
    int x1 = 2;
    int x2 = 1;
    int y2 = 2;
    int n2 = 4;

    long long result = func1(x1, n1);
    cout << "y = " << result << endl;

    long long result2 = func2(x2, y2, n2);
    cout << "y2 = " << result2 << endl;

    return 0;
}