#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string fileF, fileG;
    double a;

    cout << "Enter the filename F: ";
    cin >> fileF;
    cout << "Enter the filename G: ";
    cin >> fileG;
    cout << "Enter the  a (> 0): ";
    cin >> a;

    if (a <= 0)
    {
        cout << "a must be > 0.\n";
        return 1;
    }

    ifstream inF(fileF);
    if (!inF)
    {
        cout << "Can't open F for reading\n";
        return 1;
    }

    ofstream outG(fileG);
    ofstream temp("TEMP.tmp");

    double x;
    while (inF >> x)
    {
        if (fabs(x) < a)
        {
            outG << x << " ";
        }
        else
        {
            temp << x << " ";
        }
    }

    inF.close();
    outG.close();
    temp.close();

    ofstream rewriteF(fileF);
    ifstream readTemp("TEMP.tmp");

    while (readTemp >> x)
    {
        rewriteF << x << " ";
    }

    rewriteF.close();
    readTemp.close();

    remove("TEMP.tmp");

    cout << "File G was made. File F was uodated\n";

    return 0;
}
