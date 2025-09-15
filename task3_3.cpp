#include <iostream>
using namespace std;

void task3_3(unsigned n)
{
    int a, b, c;
    cout << "Enter three integers separated by spaces: ";
    int res1;
    long long res2;
    cin >> a >> b >> c;

    // 2^10
    if (n == 1)
    {
        if (abs(a) >= 1024 || abs(b) >= 1024 || abs(c) >= 1024)
        {
            cout << "numbers must be less than 2^10" << endl;
            return;
        }
        int res1 = a * b * c;
        cout << "Product (2^10 limit): " << res1 << endl;
    }

    // 2^21
    else if (n == 2)
    {
        if (abs(a) >= 2097152 || abs(b) >= 2097152 || abs(c) >= 2097152)
        {
            cout << "numbers must be less than 2^21" << endl;
            return;
        }
        long long res2 = 1LL * a * b * c;
        cout << "Product (2^21 limit): " << res2 << endl;
    }

    else
    {
        cout << "Invalid option!" << endl;
    }
}

int main()
{
    unsigned n;
    cout << "Enter the number(n=1 - 2^10, n=2 - 2^21): ";
    cin >> n;

    task3_3(n);
    return 0;
}