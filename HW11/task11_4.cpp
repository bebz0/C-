#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Rectangle
{
    int num;
    double x1, y1; // lower left
    double x2, y2; // upper riight
};

double area(Rectangle r)
{
    return fabs((r.x2 - r.x1) * (r.y2 - r.y1));
}

int findMaxArea(Rectangle a[], int n)
{
    double maxS = area(a[0]);
    int maxNum = a[0].num;
    for (int i = 1; i < n; i++)
    {
        double s = area(a[i]);
        if (s > maxS)
        {
            maxS = s;
            maxNum = a[i].num;
        }
    }
    cout << "Max square: " << maxS << endl;
    return maxNum;
}

void DeleteNum(Rectangle a[], int &n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].num == num)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;
            cout << "Rectangleangle # " << num << " removed" << endl;
            return;
        }
    }
    cout << "Number not found((\n";
}

void ReplaceNum(Rectangle a[], int n, int ind, Rectangle r)
{
    if (ind < 0 || ind >= n)
    {
        cout << "Wrong index\n";
        return;
    }
    a[ind] = r;
    cout << "Entry was changed\n";
}

int main()
{
    int n;
    cout << "Rectange countt: ";
    cin >> n;
    Rectangle *a = new Rectangle[n];
    ofstream f("Rectangles.txt");

    for (int i = 0; i < n; i++)
    {
        cout << "#" << i + 1 << " (num, x1 y1 x2 y2): ";
        cin >> a[i].num >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        f << a[i].num << " " << a[i].x1 << " " << a[i].y1 << " " << a[i].x2 << " " << a[i].y2 << "\n";
    }
    f.close();

    int num = findMaxArea(a, n);
    cout << "num of rect with the biggest square: " << num << endl;

    int del;
    cout << "\nEnter num to delete: ";
    cin >> del;
    DeleteNum(a, n, del);

    int ind;
    cout << "\nEnter the index (from 0) to replace: ";
    cin >> ind;
    Rectangle r;
    cout << "New data (num, x1 y1 x2 y2): ";
    cin >> r.num >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    ReplaceNum(a, n, ind, r);

    ofstream g("Rects_new.txt");
    for (int i = 0; i < n; i++)
        g << a[i].num << " " << a[i].x1 << " " << a[i].y1 << " " << a[i].x2 << " " << a[i].y2 << "\n";
    g.close();

    delete[] a;
    cout << "Updated data is in Rects_new.txt\n";
    return 0;
}
