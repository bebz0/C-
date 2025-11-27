#include <iostream>
#include "task17_1.h"
using namespace std;

int main()
{
    try
    {
        Rational r1(3, 4);
        Rational r2;

        cout << "Enter rational (format a/b): ";
        if (cin >> r2)
        {
            cout << "r1 = " << r1 << ", r2 = " << r2 << endl;
            cout << "r1 - r2 (binary) = " << (r1 - r2) << endl;
            cout << "-r1 (unary) = " << (-r1) << endl;
            cout << "r1 / r2 = " << (r1 / r2) << endl;

            saveToFile(r1, "fraction.txt");
            cout << "Saved r1 to file successfully!" << endl;
        }
        else
        {
            cerr << "Error reading input format." << endl;
        }
    }
    catch (const RationalException &ex)
    {
        cerr << "Rational Error: " << ex.what() << endl;
    }
    catch (const exception &ex)
    {
        cerr << "General Error: " << ex.what() << endl;
    }

    return 0;
}