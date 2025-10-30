#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void writeArrayToFile(double *arr, int n, const string &filename)
{
    ofstream out(filename);
    if (!out)
    {
        cout << "Can't open file for writing\n";
        return;
    }

    out << setprecision(15);
    for (int i = 0; i < n; i++)
    {
        out << arr[i];
        if (i < n - 1)
            out << " ";
    }
}

void printFileContentsCommaSeparated(const string &filename)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "Can't open file for reading\n";
        return;
    }

    double x;
    bool first = true;
    while (in >> x)
    {
        if (!first)
            cout << ", ";
        cout << x;
        first = false;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the massive length: ";
    cin >> n;

    double *arr = new double[n];

    cout << "Enter " << n << " real numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string filename;
    cout << "Enter the filenamme: ";
    cin >> filename;

    writeArrayToFile(arr, n, filename);

    cout << "File contents as a single line:\n";
    printFileContentsCommaSeparated(filename);

    delete[] arr;

    return 0;
}
