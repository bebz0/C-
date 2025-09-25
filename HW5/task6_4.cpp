#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;

    unsigned int b0 = (n >> 0) & 0xFF;
    unsigned int b1 = (n >> 8) & 0xFF;
    unsigned int b2 = (n >> 16) & 0xFF;
    unsigned int b3 = (n >> 24) & 0xFF;

    unsigned int result = (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3 << 0);

    cout << dec << result << endl;
    cout << "0x" << hex << uppercase << result;
    return 0;
}
