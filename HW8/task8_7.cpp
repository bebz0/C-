#include <iostream>
using namespace std;

static const int M = 20;

double Determinant(double A[M][M], int n)
{
    if (n == 1)
        return A[0][0];
    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0;
    double sub[M][M];

    for (int x = 0; x < n; x++)
    {
        int subi = 0; // row index for submatrix
        for (int i = 1; i < n; i++)
        {
            int subj = 0; // col index for submatrix
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                    continue;
                sub[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
        }
        // Schedule by the first row of the matrix
        det += (x % 2 == 0 ? 1 : -1) * A[0][x] * Determinant(sub, n - 1);
    }
    return det;
}

void InputMatrix(double Matrix[M][M], int n)
{
    cout << "Enter elements of matrix " << n << "x" << n << endl;
    for (int i = 0; i < n; i++)
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
    int n;
    double Matrix[M][M];

    cout << "Enter the size of matrix - n (<=20): ";
    cin >> n;

    if (n <= 0 || n > M)
    {
        cout << "n must be in 1-19" << endl;
        return 1;
    }

    InputMatrix(Matrix, n);

    double det = Determinant(Matrix, n);
    cout << "Determinant = " << det << endl;

    return 0;
}
