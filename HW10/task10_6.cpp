#include <iostream>
using namespace std;

static const int N = 100;

struct Circle
{
    double radius;
    double x;
    double y;
};

void InputCircle(Circle &c)
{
    cout << "Enter coordinates of center by space (x y): ";
    cin >> c.x >> c.y;

    cout << "Enter the radius: ";
    cin >> c.radius;
}

void OutputCircle(Circle &c)
{
    cout << "The coordinates of center: " << c.x << " " << c.y << endl;
    cout << "The radius: " << c.radius << endl;
}

int main()
{
    int n;
    cout << "How many circles? ";
    cin >> n;

    if (n <= 0 || n > N)
    {
        cout << "Invalid input\n";
        return 0;
    }

    Circle circles[N];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nCircle #" << i + 1 << ":\n";
        InputCircle(circles[i]);
    }

    cout << "\nMassive of circles:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "# " << i + 1 << " " << "circle" << endl;
        OutputCircle(circles[i]);
    }

    return 0;
}
