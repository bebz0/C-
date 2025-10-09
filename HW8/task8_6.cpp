#include <iostream>
using namespace std;

static const int M = 100;
static const int N = 100;

int Count_K(double Matrix[M][N], int m, int n, int k)
{
    double sum = 0;
    bool found = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == k)
            {
                sum += Matrix[i][j];
                found = true;
            }
        }
    }
    if (!found)
        return 0;
    return sum;
}

void InputMatrix(double Matrix[M][N], int m, int n)
{
    cout << "Enter elements of matrix " << m << "x" << n << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix [" << i << "][" << j << "] element: ";
            cin >> Matrix[i][j];
        }
    }
}

int main()
{
    int m, n;
    double Matrix[M][N];
    int k;
    cout << "Enter integer k: ";
    cin >> k;
    cout << "Enter size of m - rows: ";
    cin >> m;
    cout << "Enter size of n - cols: ";
    cin >> n;

    if (m >= 100 || n >= 100 || m <= 0 || n <= 0)
    {
        cout << "n,m must be in 1-99";
        return 1;
    }

    InputMatrix(Matrix, m, n);
    double result = Count_K(Matrix, m, n, k);
    cout << "Sum of elements where i - j = " << k << " is " << result << endl;
    return 0;
}