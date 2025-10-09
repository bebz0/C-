#include <iostream>
using namespace std;

static const int M = 25;
static const int N = 25;

void InputMatrix(double Matrix[M][N], int m, int n)
{
    cout << "Enter matrix " << m << "x" << n << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Enter n elements by space for " << i + 1 << "row: ";
        for (int j = 0; j < n; j++)
        {
            cin >> Matrix[i][j];
        }
        }
}

void OutputMatrix(double Matrix[M][N], int m, int n)
{
    cout << "\nRes matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    int m, n;
    double Matrix[M][N];

    cout << "Enter m - rows (<25): ";
    cin >> m;
    cout << "Enter n - cols (<25): ";
    cin >> n;

    if (m <= 0 || n <= 0 || m >= 25 || n >= 25)
    {
        cout << "Matrix size must be in 1 < 24 \n";
        return 1;
    }

    InputMatrix(Matrix, m, n);
    OutputMatrix(Matrix, m, n);

    return 0;
}