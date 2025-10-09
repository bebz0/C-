#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(double matrix[3][3])
{
    cout << fixed << setprecision(1);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

void replaceElement(double matrix[3][3], int i, int j, double a)
{
    matrix[i][j] = a;
}

bool isValidIndex(int i, int j)
{
    return (i >= 0 && i < 3 && j >= 0 && j < 3);
}

int main()
{
    double matrix[3][3] = {{1.0, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};
    unsigned int i;
    unsigned int j;
    double a;

    cout << "Enter index i (0-2): ";
    cin >> i;
    cout << "Enter index j (0-2): ";
    cin >> j;

    if (!isValidIndex(i, j))
    {
        cout << "Error, index must be in 0-2!" << endl;
        return 1;
    }

    cout << "Enter a: ";
    cin >> a;

    cout << "Matrix:" << endl;
    printMatrix(matrix);

    replaceElement(matrix, i, j, a);

    cout << "Res matrix:" << endl;
    printMatrix(matrix);

    return 0;
}