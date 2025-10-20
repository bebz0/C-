#include <iostream>
using namespace std;

static const int M = 20;
static const int N = 20;

void InputMatrix(double Matrix[M][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter " << "[" << i + 1 << "," << j + 1 << "]" << " element: ";
            cin >> Matrix[i][j];
        }
    }
}

void OutputMatrix(double Matrix[M][N], int m, int n)
{
    cout << "Matrix " << m << "x" << n << ":\n";
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
    cout << "Enter m - rows: ";
    cin >> m;
    cout << "Enter n - col: ";
    cin >> n;

    if (m <= 0 || n <= 0 || m > M || n > N)
    {
        cout << "Size of matrix must be in 1-19\n";
        return 1;
    }

    double Matrix[M][N];
    InputMatrix(Matrix, m, n);
    OutputMatrix(Matrix, m, n);
    return 0;
}