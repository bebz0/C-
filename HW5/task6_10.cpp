#include <iostream>
#include <iomanip>
using namespace std;

int bit_length(unsigned long long n)
{
    int b = 0;
    while (n)
    {
        n >>= 1;
        b++;
    }
    return b;
}

unsigned long long swap_ends(unsigned long long n)
{
    int b = bit_length(n);
    if (b < 16)
        return n;

    int shift = b - 8;
    unsigned long long first = (n >> shift) & 0xFF;
    unsigned long long last = n & 0xFF;

    unsigned long long mask = ~((0xFFULL << shift) | 0xFF);
    return (last << shift) | (n & mask) | first;
}

int main()
{
    unsigned long long n;
    cout << "Enter number: ";
    cin >> n;
    if (!cin)
    {
        cout << "Invalid input\n";
        return 1;
    }

    unsigned long long swapped = swap_ends(n);

    cout << "\nOriginal: " << dec << n << "  Hex: " << hex << showbase << n << "\n";
    if (n == swapped)
        cout << "Too small to swap\n";
    else
        cout << "Decimal: " << dec << swapped << "  Hex: " << hex << showbase << swapped << "\n";
}
