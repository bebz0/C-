#include <iostream>
using namespace std;

// г

int main()
{
    int f0 = 0.0, f1 = 1.0;
    int sum = 0.0;

    while (f0 <= 1000)
    {
        sum += f0;
        int next = f0 + f1;
        f0 = f1;
        f1 = next;
    }

    cout << "Res: " << sum << endl;
    return 0;
}