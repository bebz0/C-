#include <iostream>
using namespace std;

void task3_2(unsigned n)
{
    unsigned last_digit = n % 10;
    unsigned second_digit = (n / 10) % 10;
    unsigned first_digit = n / 100;

    if ((last_digit == second_digit) || (first_digit == second_digit) || (last_digit == first_digit))
    {
        return;
    }
    unsigned n1 = first_digit * 100 + second_digit * 10 + last_digit;
    unsigned n2 = first_digit * 100 + last_digit * 10 + second_digit;
    unsigned n3 = last_digit * 100 + first_digit * 10 + second_digit;
    unsigned n4 = last_digit * 100 + second_digit * 10 + first_digit;
    unsigned n5 = second_digit * 100 + first_digit * 10 + last_digit;
    unsigned n6 = second_digit * 100 + last_digit * 10 + first_digit;
    cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << " " << n6 << endl;
}

int main()
{
    unsigned n;
    cout << "Enter the number: ";
    cin >> n;
    if (n >= 100 && n <= 999)
    {
        task3_2(n);
    }
    else
    {
        cout << "number is not three-digit" << endl;
        return 1;
    }

    return 0;
}