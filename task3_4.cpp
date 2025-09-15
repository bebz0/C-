#include <iostream>
using namespace std;

void task3_4(unsigned char n)
{
    unsigned short y = static_cast<unsigned short>(n) << 8;
    cout << "16-bit number: " << y << endl;
}

int main()
{
    unsigned int tmp;
    cout << "Enter an 8-bit number (0-255): ";
    cin >> tmp;

    if (tmp > 255)
    {
        cout << "Error: not an 8-bit number" << endl;
        return 1;
    }

    task3_4(static_cast<unsigned char>(tmp));
    return 0;
}
