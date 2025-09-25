#include <iostream>
#include <iomanip> // for hex etc
using namespace std;

int main()
{
    unsigned long long m;
    int j;
    cin >> m >> j;

    unsigned long long result = m & ~(1ULL << j);

    cout << dec << result << endl;
    cout << "0x" << hex << uppercase << result << endl;

    return 0;
}
