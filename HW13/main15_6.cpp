#include "task15_6.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(1);
    Rectangle r1(0.0, 10.0, 10.0, 10.0);
    Rectangle r2(5.0, 5.0, 10.0, 10.0);
    Rectangle r3(100.0, 100.0, 1.0, 1.0);

    cout << "Rectangle R1 (0, 10, 10, 10):" << endl;
    r1.display();
    cout << "Area: " << r1.getArea() << endl;
    cout << "Perimeter: " << r1.getPerimeter() << endl;

    cout << "\nRectangle R2 (5, 5, 10, 10):" << endl;
    r2.display();

    cout << "\nIntersection R1 and R2:" << endl;
    Rectangle intersection = r1.getIntersection(r2);
    intersection.display();

    cout << "\nIntersection R1 and R3 (empty):" << endl;
    Rectangle noIntersection = r1.getIntersection(r3);
    noIntersection.display();

    return 0;
}