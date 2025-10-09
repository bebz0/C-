#include <iostream>

using namespace std;

double **createMatrix2D(int n)
{
    double **matrix = new double *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new double[n];
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = 0.0;
        }
    }
    return matrix;
}

void deleteMatrix2D(double **matrix, int n)
{
    if (matrix != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            delete[] matrix[i]; // row
        }
        delete[] matrix;
    }
}

void inputMatrix2D(double **matrix, int n)
{
    cout << "\nEnter matrix " << n << "x" << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix2D(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

double **multiplyMatrices2D(double **matrixA, double **matrixB, int n)
{
    double **resultMatrix = createMatrix2D(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return resultMatrix;
}

void run2DVersion()
{
    int n;
    cout << "2D Array (double**)\n";
    cout << "Enter the size of the square matrices (n): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Sze must be a positive number\n";
        return;
    }

    double **A = createMatrix2D(n);
    inputMatrix2D(A, n);

    double **B = createMatrix2D(n);
    inputMatrix2D(B, n);

    cout << "\nMatrix A:\n";
    outputMatrix2D(A, n);

    cout << "\nMatrix B:\n";
    outputMatrix2D(B, n);

    double **C = multiplyMatrices2D(A, B, n);
    cout << "\nMultiplication Result (C = A * B):\n";
    outputMatrix2D(C, n);

    deleteMatrix2D(A, n);
    deleteMatrix2D(B, n);
    deleteMatrix2D(C, n);
}

double *createMatrixLinear(int n)
{
    double *matrix = new double[n * n];
    for (int i = 0; i < n * n; ++i)
    {
        matrix[i] = 0.0;
    }
    return matrix;
}

void deleteMatrixLinear(double *matrix)
{
    if (matrix != 0)
    {
        delete[] matrix;
    }
}

void inputMatrixLinear(double *matrix, int n)
{
    cout << "\nEnter matrix " << n << "x" << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix[" << i + 1 << "][" << j + 1 << "] = ";
            // linear index: i * n + j
            cin >> matrix[i * n + j];
        }
    }
}

void outputMatrixLinear(double *matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i * n + j] << "\t";
        }
        cout << "\n";
    }
}

double *multiplyMatricesLinear(double *matrixA, double *matrixB, int n)
{
    double *resultMatrix = createMatrixLinear(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                // C[i][j] += A[i][k] * B[k][j]
                resultMatrix[i * n + j] += matrixA[i * n + k] * matrixB[k * n + j];
            }
        }
    }
    return resultMatrix;
}

void runLinearVersion()
{
    int n;
    cout << "Linear Array (double*)\n";
    cout << "Enter the size of the square matrices (n): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Size must be a positive number\n";
        return;
    }

    double *A = createMatrixLinear(n);
    inputMatrixLinear(A, n);

    double *B = createMatrixLinear(n);
    inputMatrixLinear(B, n);

    cout << "\nMatrix A:\n";
    outputMatrixLinear(A, n);

    cout << "\nMatrix B:\n";
    outputMatrixLinear(B, n);

    double *C = multiplyMatricesLinear(A, B, n);
    cout << "\nMultiplication Result (C = A * B):\n";
    outputMatrixLinear(C, n);

    deleteMatrixLinear(A);
    deleteMatrixLinear(B);
    deleteMatrixLinear(C);
}

int main()
{
    run2DVersion();
    runLinearVersion();
    return 0;
}