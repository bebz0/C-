#include <iostream>
using namespace std;

int main()
{
    unsigned int m, n;
    cout << "Enter two 32-bit numbers: ";
    cin >> m >> n;

    unsigned int diff = m ^ n; // bits where the numbers are different

    cout << "Positions of differing bits: ";
    for (int i = 0; i < 32; ++i)
    {
        if (diff & (1u << i))
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}
