#include "task15_2.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    Point **polygon = nullptr;
    int vertexCount = 0;
    string Resp;

    while (true)
    {
        cout << "\nDo u wanna enter vertex? (enter 'No' if not): ";
        cin >> Resp;

        if (Resp == "No")
        {
            break;
        }
        Point *newVertex = new Point();

        cout << "Enter ccoord for vertex " << Point::counter() << ":" << endl;
        newVertex->input();
        Point **temp = new Point *[vertexCount + 1];
        for (int i = 0; i < vertexCount; ++i)
        {
            temp[i] = polygon[i];
        }
        temp[vertexCount] = newVertex;
        if (polygon != nullptr)
        {
            delete[] polygon;
        }

        polygon = temp;
        vertexCount++;

        cout << "Numbers of vertex: " << Point::counter() << endl;
        double perimeter = 0.0;
        if (vertexCount < 2)
        {
            cout << "Perimetr: 0.00 (less than 2 vertex)" << endl;
        }
        else if (vertexCount == 2)
        {
            perimeter = polygon[0]->distance(*polygon[1]);
            cout << "Lenght of segment: " << fixed << setprecision(2) << perimeter << endl;
        }
        else
        {
            for (int i = 0; i < vertexCount; ++i)
            {
                perimeter += polygon[i]->distance(*polygon[(i + 1) % vertexCount]);
            }
            cout << "Perimeter: " << fixed << setprecision(2) << perimeter << endl;
        }

        for (int i = 0; i < vertexCount; ++i)
        {
            delete polygon[i];
        }
        if (polygon != nullptr)
        {
            delete[] polygon;
        }
        return 0;
    }
}