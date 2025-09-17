#include <iostream>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;

    unsigned long long p = 1;
    while (p <= n)
    {
        p <<= 1; // bit shift
    }

    cout << p << endl;
    return 0;
}
