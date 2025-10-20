#include <iostream>
using namespace std;

const int N = 25;

void InputMatrix(double Matrix[N][N], int n)
{
    cout << "\nEnter matrix " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> Matrix[i][j];
        }
    }
}

void OutputMatrix(double A[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Transpose(double Matrix[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double temp = Matrix[i][j];
            Matrix[i][j] = Matrix[j][i];
            Matrix[j][i] = temp;
        }
    }
}

int main()
{
    int n;
    double Matrix[N][N];

    cout << "Enter size of matrix - n (<25): ";
    cin >> n;

    if (n <= 0 || n >= 25)
    {
        cout << "Must be in 1-24\n";
        return 1;
    }

    InputMatrix(Matrix, n);

    cout << "\nMatrix:\n";
    OutputMatrix(Matrix, n);

    Transpose(Matrix, n);

    cout << "\nTranspose Matrix:\n";
    OutputMatrix(Matrix, n);

    return 0;
}
