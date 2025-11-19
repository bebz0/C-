#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    string line;
    cout << "Enter string in format A=..., B=... C=... :" << endl;
    getline(cin, line);

    stringstream ss(line);
    double a, b, c;
    char lit_A, eq1, comma, lit_B, eq2, lit_C, eq3;

    ss >> lit_A >> eq1 >> a >> comma >> lit_B >> eq2 >> b >> lit_C >> eq3 >> c;

    if (ss.fail() || lit_A != 'A' || eq1 != '=' || comma != ',' ||
        lit_B != 'B' || eq2 != '=' || lit_C != 'C' || eq3 != '=' || !ss.eof())
    {
        cout << "Invalid input format" << endl;
        return 1;
    }

    if (a <= 0 || b <= 0 || c <= 0)
    {
        cout << "Calculation is not possible." << endl;
        cout << "Numbers A, B, and C must be strictly positive." << endl;
        return 1;
    }
    double harmonicMean = 3.0 / ((1.0 / a) + (1.0 / b) + (1.0 / c));
    cout << "\nHarmonic mean calculated successfully." << endl;
    cout << setprecision(6);
    cout << "  Scientific format: " << scientific << harmonicMean << endl;
    cout << "  Fixed format:      " << fixed << harmonicMean << endl;

    return 0;
}