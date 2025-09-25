#include <iostream>

using namespace std;

int main()
{
    unsigned char n;
    cout << "Enter n: ";
    cin >> n;

    if (n >= 64)
    {
        cout << "n must be < 64";
        return 1;
    }

    unsigned long long res = 1ULL << n;
    cout << "2^" << n << " = " << res << endl;
    return 0;
}
