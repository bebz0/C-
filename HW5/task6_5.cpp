#include <iostream>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;

    int max_count = 0, current = 0;
    while (n > 0)
    {
        if (n & 1)
        { // if last one  = 1
            current++;
            if (current > max_count)
                max_count = current;
        }
        else
        {
            current = 0;
        }
        n >>= 1; // right
    }

    cout << max_count << endl;
    return 0;
}
