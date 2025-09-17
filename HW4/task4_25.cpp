#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    long long r = n % m; // resuiadall after extracting a whole part
    if (r == 0)
    {
        cout << 0; // no period, fraction complete
        return 0;
    }

    long long start = r;
    int length = 0;

    // when the remainder  repeat
    while (true)
    {
        r = (r * 10) % m;
        length++;

        if (r == 0)
        { // resuidal is zero - fraction is complete
            cout << 0;
            break;
        }
        if (r == start)
        { // the init resuidall is repeated - period
            cout << length;
            break;
        }
    }

    return 0;
}
