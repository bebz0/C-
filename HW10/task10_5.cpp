#include <iostream>
using namespace std;

struct mountain
{
    char title[80];
    int altitude;
};

void fillmountains(mountain mountains[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << "\nEnter mountain #" << i + 1 << ": ";
        cin >> mountains[i].title;
        cout << "Height (m): ";
        cin >> mountains[i].altitude;
    }
}

void showmountains(mountain mountains[], int count)
{
    cout << "\nList of mountains:\n";
    for (int i = 0; i < count; ++i)
        cout << "- " << mountains[i].title << ": " << mountains[i].altitude << " м" << endl;
}

int findMax(mountain mountains[], int count)
{
    int pos = 0;
    for (int i = 1; i < count; ++i)
        if (mountains[i].altitude > mountains[pos].altitude)
            pos = i;
    return pos;
}

bool sameName(const char a[], const char b[])
{
    int i = 0;
    while (true)
    {
        if (a[i] != b[i])
            return false;
        if (a[i] == '\0')
            return true;
        ++i;
    }
}

void getHeight(mountain mountains[], int count, const char name[])
{
    for (int i = 0; i < count; ++i)
    {
        if (sameName(mountains[i].title, name))
        {
            cout << "Height of mountain " << name << " = " << mountains[i].altitude << " м\n";
            return;
        }
    }
    cout << "mountain with name \"" << name << "\" wasn't founded\n";
}

int main()
{
    int n;
    cout << "How much mountains? ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalud input\n";
        return 0;
    }

    mountain arr[100];
    fillmountains(arr, n);
    showmountains(arr, n);

    int top = findMax(arr, n);
    cout << "\nThe highest mountain — " << arr[top].title
         << " (" << arr[top].altitude << " м)\n";

    char query[80];
    cout << "\nEnter mountain name to search: ";
    cin >> query;

    getHeight(arr, n, query);

    return 0;
}
