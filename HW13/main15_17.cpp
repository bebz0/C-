#include "task15_17.h"
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of intervals (n): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The number must be >0" << endl;
        return 1;
    }

    Interval *arr = new Interval[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Interval " << (i + 1) << "/" << n << ":" << endl;
        arr[i].input();
    }

    cout << "\nEntered intervals:" << endl;
    for (int i = 0; i < n; ++i)
    {
        arr[i].display();
        cout << endl;
    }

    double minLeft = 0;
    double maxRight = 0;
    bool hasValidInterval = false;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i].isEmpty())
            continue;

        if (!hasValidInterval)
        {
            minLeft = arr[i].getLeft();
            maxRight = arr[i].getRight();
            hasValidInterval = true;
        }
        else
        {
            if (arr[i].getLeft() < minLeft)
            {
                minLeft = arr[i].getLeft();
            }
            if (arr[i].getRight() > maxRight)
            {
                maxRight = arr[i].getRight();
            }
        }
    }

    if (hasValidInterval)
    {
        double distance = maxRight - minLeft;
        cout << "\nMinimum left endpoint: " << minLeft << endl;
        cout << "Maximum right endpoint: " << maxRight << endl;
        cout << "Distance between the farthest endpoints: " << distance << endl;
    }
    else
    {
        cout << "\nNo valid intervals were entered" << endl;
    }

    delete[] arr;
    return 0;
}