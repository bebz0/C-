#include <iostream>
using namespace std;

void task3(unsigned n)
{
    unsigned ones = n % 10;        // last
    unsigned tens = (n / 10) % 10; // middle
    unsigned hunds = n / 100;      // first

    // а) number output
    cout << "Hundreds: " << hunds << endl;
    cout << "Tens: " << tens << endl;
    cout << "Ones: " << ones << endl;

    // б) sum of numbers
    unsigned sum = hunds + tens + ones;
    cout << "Sum of digits: " << sum << endl;

    // в) number from right to left
    unsigned reversed = ones * 100 + tens * 10 + hunds;
    cout << "Reversed number: " << reversed << endl;
}

int main()
{
    unsigned n;
    cout << "Enter a three-digit number: ";
    cin >> n;

    if (n >= 100 && n <= 999)
    {
        task3(n);
    }
    else
    {
        cout << "number is not three-digit" << endl;
        return 1;
    }

    return 0;
}
