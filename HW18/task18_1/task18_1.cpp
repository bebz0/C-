#include <iostream>
#include <string>
#include "task17_1.cpp" // Rational
using namespace std;

namespace MySpace {
    template <typename T>
    T findMaximum(T a, T b) {
        return (a > b) ? a : b;
    }
}

int main() {
    try {
        // Test 1: numbers
        int i1 = 20, i2 = 40;
        double d1 = 4.8, d2 = 3.4;

        cout << "Max int: " << MySpace::findMaximum(i1, i2) << endl;
        cout << "Max double: " << MySpace::findMaximum(d1, d2) << endl;

        // Test 2: string
        // Answer onn question: Yes, it works cause string has operator >
        string s1 = "Green";
        string s2 = "Yellow";
        cout << "Max string: " << MySpace::findMaximum(s1, s2) << endl;

        // Test 3: Rational
        Rational r1(2, 3); 
        Rational r2(3, 4);

        // Rational already has operator >
        Rational maxRes = MySpace::findMaximum(r1, r2);

        cout << "Max Rational (" << r1 << " vs " << r2 << "): " 
                  << maxRes << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}