#include <iostream>

using namespace std;

double **createMatrix(int rows, int cols)
{
    double **matrix = new double *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new double[cols];
    }
    return matrix;
}

void deleteMatrix(double **matrix, int rows)
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

void printMatrix(double **matrix, int rows, int cols)
{
    if (matrix == nullptr)
        return;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void fillMatrixFromConsole(double **matrix, int rows, int cols)
{
    cout << "\nEnter elements:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "ellement [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int findColumnWithMaxSum(double **matrix, int rows, int cols)
{
    if (cols == 0)
        return -1;

    int maxIndex = 0;
    double maxSum = 0.0;

    // Calculate the sum of first col to init maxSum
    for (int i = 0; i < rows; ++i)
    {
        maxSum += matrix[i][0];
    }

    // Go through the remain cols,index 1
    for (int j = 1; j < cols; ++j)
    {
        double currentSum = 0.0;
        for (int i = 0; i < rows; ++i)
        {
            currentSum += matrix[i][j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = j;
        }
    }
    return maxIndex;
}

double **insertColumnAfter(double **originalMatrix, int rows, int oldCols, int columnIndex)
{
    int newCols = oldCols + 1;
    double **newMatrix = createMatrix(rows, newCols);
    int insertPosition = columnIndex + 1;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < newCols; ++j)
        {
            if (j < insertPosition)
            {
                newMatrix[i][j] = originalMatrix[i][j];
            }
            else if (j == insertPosition)
            {
                newMatrix[i][j] = 0.0;
            }
            else
            {
                newMatrix[i][j] = originalMatrix[i][j - 1];
            }
        }
    }
    return newMatrix;
}

int main()
{

    int N, M;
    cout << "Enter size of rows (N): ";
    cin >> N;
    cout << "Enter size of cols (M): ";
    cin >> M;

    if (N <= 0 || M <= 0)
    {
        cout << "M and N must be positive" << endl;
        return 1;
    }

    double **matrix = createMatrix(N, M);
    fillMatrixFromConsole(matrix, N, M);

    cout << "\nMatrix before" << endl;
    printMatrix(matrix, N, M);

    int colIndex = findColumnWithMaxSum(matrix, N, M);
    cout << "\nCol with the largest sum of elements has the index: " << colIndex << endl;

    double **modifiedMatrix = insertColumnAfter(matrix, N, M, colIndex);

    cout << "\nModified matrix, was added col after index " << colIndex << "" << endl;
    printMatrix(modifiedMatrix, N, M + 1);

    cout << "\nFree memore" << endl;
    deleteMatrix(matrix, N);
    deleteMatrix(modifiedMatrix, N);

    return 0;
}