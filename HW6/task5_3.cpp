#include <iostream>
using namespace std;

int func(int n)
{
    int step = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        step++;
    }
    return step;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int steps = func(n);
    cout << "Number " << n << steps << " steps." << endl;

    int maxstep = 0;
    int num = 0;

    for (int n = 1; n < 1000; n++)
    {
        int steps = func(n);
        if (steps > maxstep)
        {
            maxstep = steps;
            num = n;
        }
    }
    cout << "Num of steps for n: " << maxstep << endl;
    return 0;
}