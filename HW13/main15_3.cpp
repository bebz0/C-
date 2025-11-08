#include "task15_3.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "\nConstr by size (N=4):" << endl;
    Polynomial p1(4);
    p1.setCoefficient(3, 5.5);
    p1.setCoefficient(1, -2.1);
    p1.display();

    cout << "\nConstr by size  (N=3):" << endl;
    double data[] = {1.1, 2.2, 3.3};
    Polynomial p2(3, data);
    p2.display();

    cout << "\nCopy-constr (p3 = p2):" << endl;
    Polynomial p3 = p2;
    p3.display();

    cout << "\nOperator == (p1 = p2):" << endl;
    p1 = p2;
    p1.display();

    cout << "\nSaved to binary (poly.bin):" << endl;
    if (saveToBinary(p2, "poly.bin"))
    {
        cout << " p2 was saved." << endl;
    }

    cout << "\nDownloading from a binary file:" << endl;
    try
    {
        Polynomial p4 = loadFromBinary("poly.bin");
        cout << "p4 was saved:" << endl;
        p4.display();
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}