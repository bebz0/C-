#include <iostream>
using namespace std;

static const int M = 100;
static const int N = 100;

void InputMatrix(double Matrix[N][M], int n, int m)
{
    cout << "Enter elements of matrix " << m << "x" << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Matrix [" << i << "][" << j << "] element: ";
            cin >> Matrix[i][j];
        }
    }
}

void PrintMatrix(double Matrix[N][M], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

void MaxCol(double Matrix[N][M], int n, int m)
{
    int maxRow = 0;
    double maxVal = Matrix[0][0];

    // Find which row contains the largest el
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matrix[i][j] > maxVal)
            {
                maxVal = Matrix[i][j];
                maxRow = i;
            }
        }
    }

    // If this row is already the last one - nothin
    if (maxRow == n - 1)
        return;

    // Otherwise, swap this row with the last one
    for (int j = 0; j < m; j++)
    {
        double temp = Matrix[maxRow][j];
        Matrix[maxRow][j] = Matrix[n - 1][j];
        Matrix[n - 1][j] = temp;
    }
}
int main()
{
    int n, m;
    double Matrix[N][M];

    cout << "Enter n-rows (1-99): ";
    cin >> n;
    cout << "Enter m-cols (1-99): ";
    cin >> m;
    if (n <= 0 || n >= N || m <= 0 || m >= M)
    {
        cout << "size must be in 1-99\n";
        return 1;
    }
    InputMatrix(Matrix, n, m);
    cout << "\nBefore:\n";
    PrintMatrix(Matrix, n, m);
    MaxCol(Matrix, n, m);

    cout << "\nAfter:\n";
    PrintMatrix(Matrix, n, m);
    return 0;
}
