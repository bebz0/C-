#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
const string INPUT_FILENAME = "input.txt";
const string OUTPUT_FILENAME = "output.txt";

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0)
    {
        cerr << "n must be >0" << endl;
        return 1;
    }
    int *m = new int[n];
    double *x = new double[n];
    double *res = new double[n];

    cout << "Enter " << n << " integers bby space: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
    }
    ifstream inFile(INPUT_FILENAME);
    if (!inFile.is_open())
    {
        cerr << "Cant open: " << INPUT_FILENAME << endl;
        delete[] m;
        delete[] x;
        delete[] res;
        return 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!(inFile >> x[i]))
        {
            cerr << "File" << INPUT_FILENAME << " incorrect" << endl;
            if (inFile.eof())
            {
                cerr << "file has more than " << n << " integers" << endl;
            }
            else
            {
                cerr << "File has others types" << endl;
            }

            inFile.close();
            delete[] m;
            delete[] x;
            delete[] res;
            return 1;
        }
    }
    inFile.close();
    for (int i = 0; i < n; ++i)
    {
        res[i] = pow(x[i], m[i]);
    }
    ofstream outFile(OUTPUT_FILENAME);
    if (!outFile.is_open())
    {
        cerr << "Can't made '" << OUTPUT_FILENAME << endl;
        delete[] m;
        delete[] x;
        delete[] res;
        return 1;
    }

    outFile << fixed << setprecision(6);
    for (int i = 0; i < n; ++i)
    {
        outFile << res[i] << endl;
    }
    outFile.close();

    cout << "Was saved in " << OUTPUT_FILENAME << endl;
    delete[] m;
    delete[] x;
    delete[] res;
    return 0;
}