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

Data GetTomorrow(const Data &d)
{
    Data tomorrow = d;

    static const int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int md = mdays[d.month];
    bool year_365 = (d.year % 4 == 0 && (d.year % 100 != 0 || d.year % 400 == 0));
    if (d.month == 2 && year_365)
    {
        md = 29;
    }
    tomorrow.day++;
    if (tomorrow.day > md)
    {
        tomorrow.day = 1;
        tomorrow.month++;

        if (tomorrow.month > 12)
        {
            tomorrow.month = 1;
            tomorrow.year++;
        }
    }

    return tomorrow;
}

const char *GetDayOfWeek(const Data &d)
{
    static const char *week_days[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int year = d.year;
    int month = d.month;
    int day = d.day;
    // Sakamato algorithm
    if (month < 3)
        year--;
    int index = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

    return week_days[index];
}

int main()
{
    Data my_date;
    InputData(my_date);

    if (!ValidateData(my_date))
    {
        cout << "Invalid data\n";
        return 0;
    }

    cout << "This date: ";
    OutputData(my_date);

    Data next = GetTomorrow(my_date);
    cout << "Tomorrow will be: ";
    OutputData(next);

    const char *dayName = GetDayOfWeek(my_date);
    cout << "This is the day of the week: " << dayName << endl;

    return 0;
}