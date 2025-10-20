#include <iostream>
using namespace std;

static const int PASS_MARK = 35; // Like in mechmat :)
static const int N = 100;

struct Student
{
    char surname[50]; // some lim
    int group;
    int grade1;
    int grade2;
    int grade3;
};

void inputStudent(Student &s)
{
    cout << "Surname: ";
    cin >> s.surname;
    cout << "Group number: ";
    cin >> s.group;
    cout << "Grade 1: ";
    cin >> s.grade1;
    cout << "Grade 2: ";
    cin >> s.grade2;
    cout << "Grade 3: ";
    cin >> s.grade3;
}

void outputStudent(const Student &s)
{
    cout << s.surname << " | Group " << s.group
         << " | Grades: " << s.grade1 << ", "
         << s.grade2 << ", " << s.grade3 << endl;
}

bool hasDebts(const Student &s)
{
    return (s.grade1 < PASS_MARK || s.grade2 < PASS_MARK || s.grade3 < PASS_MARK);
}

double averageGrade(const Student &s)
{
    return (s.grade1 + s.grade2 + s.grade3) / 3.0;
}

void printStudentsWithDebts(Student students[], int n)
{
    cout << "\nStudents with debts:\n";
    bool foundDebt = false;
    for (int i = 0; i < n; ++i)
    {
        if (hasDebts(students[i]))
        {
            outputStudent(students[i]);
            foundDebt = true;
        }
    }
    if (!foundDebt)
    {
        cout << "There are no students in debt\n";
    }
}

void printTopStudent(Student students[], int n)
{
    int topIndex = 0;
    double maxAvg = averageGrade(students[0]);

    for (int i = 1; i < n; ++i)
    {
        double avg = averageGrade(students[i]);
        if (avg > maxAvg)
        {
            maxAvg = avg;
            topIndex = i;
        }
    }

    cout << "\nStudent with the highest mean grade:\n";
    outputStudent(students[topIndex]);
    cout << "Mean grade: " << maxAvg << endl;
}

int main()
{
    int n;
    cout << "How many students?: ";
    cin >> n;

    if (n <= 0 || n > N)
    {
        cout << "Invalid input\n";
        return 0;
    }

    Student students[N];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nStudent #" << i + 1 << ":\n";
        inputStudent(students[i]);
    }

    printStudentsWithDebts(students, n);
    printTopStudent(students, n);

    return 0;
}
