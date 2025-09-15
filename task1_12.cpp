#include <iostream>
using namespace std;

int main()
{
    double inner = 1 + 1.0 / 3;    // 1 + 1/3
    double next = 7 + 1.0 / inner; // 7 + 1/(1 + 1/3)
    double outer = 4 + 1.0 / next; // 4 + 1/(7 + 1/(1 + 1/3))
    double T = 365 + 1.0 / outer;  // 365 + 1/(4 + 1/(7 + 1/(1 + 1/3)))

    cout << "Result = " << T << endl;

    return 0;
}