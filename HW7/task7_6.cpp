#include <iostream>
using namespace std;

const int N = 20;

void func1(double vec[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> vec[i];
    }
}

void func2(const double vec[], int n)
{
    cout << "(";
    for (int i = 0; i < n; i++)
    {
        cout << vec[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << ")";
}

void func3(const double a[], const double b[], double res[], int n)
{
    for (int i = 0; i < n; i++)
    {
        res[i] = a[i] + b[i];
    }
}

double func4(const double a[], const double b[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0 || n >= N)
    {
        cout << "Incorrect dimension !" << endl;
        return 1;
    }

    double v1[N], v2[N], vSum[N];

    cout << "\nEntering first vector:\n";
    func1(v1, n);

    cout << "\nEntering second vector:\n";
    func1(v2, n);

    func3(v1, v2, vSum, n);

    double dot = func4(v1, v2, n);

    cout << "\nFirst vector: ";
    func2(v1, n);
    cout << "\nSecond vector: ";
    func2(v2, n);
    cout << "\nSum of vectors: ";
    func2(vSum, n);
    cout << "\nDot: " << dot << endl;

    return 0;
}
