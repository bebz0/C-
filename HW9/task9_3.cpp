#include <iostream>
using namespace std;

double *inputVector(int n)
{
    double *v = new double[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    return v;
}

void freeVector(double *v)
{
    delete[] v;
}

double *difVectors(double *a, double *b, int n)
{
    double *result = new double[n];
    for (int i = 0; i < n; ++i)
    {
        result[i] = a[i] - b[i];
    }
    return result;
}

void printVector(double *v, int n)
{
    for (int i = 0; i < n; ++i)
        cout << v[i] << "\t";
    cout << endl;
}

int main()
{
    int n1, n2;
    cout << "Enter size of first vec: ";
    cin >> n1;
    double *v1 = inputVector(n1);

    cout << "Enter size of second vec: ";
    cin >> n2;
    double *v2 = inputVector(n2);

    if (n1 == n2)
    {
        double *diff = difVectors(v1, v2, n1);
        cout << "Vector difference: ";
        printVector(diff, n1);
        freeVector(diff);
    }
    else
    {
        cout << "Size of vectors is not tbe same" << endl;
    }

    freeVector(v1);
    freeVector(v2);

    return 0;
}
