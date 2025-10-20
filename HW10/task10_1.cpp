#include <iostream>
using namespace std;

struct Data
{
    int day;
    int month;
    int year;
};

bool ValidateData(Data &d)
{
    if (d.year < 1)
        return false;
    if (d.month < 1 || d.month > 12)
        return false;
    if (d.day < 1)
        return false;
    static const int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int md = mdays[d.month];
    bool year_365 = (d.year % 4 == 0 && (d.year % 100 != 0 || d.year % 400 == 0));
    if (d.month == 2 && year_365)
        md = 29;
    return d.day <= md;
}

void InputData(Data &d)
{
    cout << "Enter day/month/year by space: ";
    cin >> d.day >> d.month >> d.year;
}

void OutputData(Data &d)
{
    if (!ValidateData(d))
    {
        cout << "Invalid data\n";
    }
    else
        cout << "Day/Month/Year: " << d.day << "/" << d.month << "/" << d.year << endl;
}

struct Cell
{
    int num;
    char letter;
};

bool ValidateCell(Cell &c)
{
    return (c.letter >= 'a' && c.letter <= 'h') && (c.num >= 1 && c.num <= 8);
}

void InputCell(Cell &c)
{
    cout << "Enter cell num and cell letter by space: ";
    cin >> c.num >> c.letter;
}

void OutputCell(Cell &c)
{
    if (!ValidateCell(c))
    {
        cout << "Invalid input";
    }
    else
        cout << "The cell: " << c.num << c.letter << endl;
}

struct Point
{
    double x;
    double y;
};

struct Rectangle
{
    Point topLeft;
    Point bottomRight;
};

bool ValidateRectangle(const Rectangle &r)
{
    return (r.topLeft.x < r.bottomRight.x && r.topLeft.y > r.bottomRight.y);
}

void InputPoint(Point &p)
{
    cout << "Enter point coordinates (x y): ";
    cin >> p.x >> p.y;
}

void InputRectangle(Rectangle &r)
{
    cout << "Enter top-left vertex: " << endl;
    InputPoint(r.topLeft);
    cout << "Enter bottom-right vertex: " << endl;
    InputPoint(r.bottomRight);
}

void OutputRectangle(Rectangle &r)
{
    if (!ValidateRectangle(r))
    {
        cout << "Invalid coordinates" << endl;
        r = {{0, 0}, {0, 0}};
    }
    else
        cout << "Rectangle defined by Top-Left (" << r.topLeft.x << ", " << r.topLeft.y
             << ") and Bottom-Right (" << r.bottomRight.x << ", " << r.bottomRight.y << ")" << endl;
}

struct Polynom
{
    int degree;
    double *coef;
};

bool ValidatePolynom(Polynom &p)
{
    return (p.degree >= 0);
};

void InputPolynom(Polynom &p)
{
    cout << "Enter degree and coefficients by space: ";
    cin >> p.degree;
    p.coef = new double[p.degree + 1];
    for (int i = 0; i <= p.degree; i++)
    {
        cin >> p.coef[i];
    }
}
void OutputPolynom(Polynom &p)
{
    cout << "P(x) = ";
    for (int i = 0; i <= p.degree; i++)
    {
        double k = p.coef[i];
        int d = p.degree - i;
        if (i > 0 && k > 0)
            cout << "+";
        if (d == 0)
            cout << k;
        else if (d == 1)
            cout << k << "x";
        else
            cout << k << "x^" << d;
    }
    cout << "\n";
}
void FreePolynom(Polynom &p)
{
    delete[] p.coef;
}

int main()
{
    Data d;
    InputData(d);
    OutputData(d);
    cout << "--------------------" << endl;

    Cell c;
    InputCell(c);
    OutputCell(c);
    cout << "--------------------" << endl;

    Rectangle r;
    InputRectangle(r);
    OutputRectangle(r);
    cout << "--------------------" << endl;

    Polynom p;
    InputPolynom(p);
    OutputPolynom(p);

    return 0;
}
