#include <iostream>
using namespace std;
#include <cmath>

const static int N = 100;

int InputArray(int *arr)
{
    int i = 0;
    int x;
    while (i < N)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        arr[i++] = x;
    }
    return i;
}

bool isSquare(int x)
{
    if (x < 0)
        return false;
    for (int i = 0; i * i <= x; i++)
    {
        if (i * i == x)
            return true;
    }
    return false;
}

bool isCube(int x)
{
    if (x < 0)
        return false;
    for (int i = 0; i * i * i <= x; i++)
    {
        if (i * i * i == x)
            return true;
    }
    return false;
}

int main()
{
    int *arr = new int[N];
    int n = InputArray(arr);

    int countSquares = 0, countCubes = 0;

    for (int i = 0; i < n; i++)
    {
        if (isSquare(arr[i]))
            countSquares++;
        if (isCube(arr[i]))
            countCubes++;
    }

    cout << "Num of sq: " << countSquares << endl;
    cout << "Num of cub: " << countCubes << endl;

    return 0;
}