#include <iostream>
using namespace std;

int main()
{
    int Matr[3][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};

    int N;
    int M;

    cout << "Enter N and M: ";
    cin >> N >> M;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matr[i][j] == M)
            {
                Matr[i][j] = N;
            }
        }
    }

    cout << "Matrix result:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Matr[i][j] << " ";
        }
    }
    return 0;
}