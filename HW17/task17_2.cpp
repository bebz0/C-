#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void clearBuffer()
{
    while (cin.get() != '\n')
        ;
}

class Human
{
protected:
    string name;
    string gender;
    int age;

public:
    Human() : name(""), gender(""), age(0) {}
    virtual ~Human() {}

    virtual void input()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter gender (M/F): ";
        getline(cin, gender);

        cout << "Enter age: ";
        cin >> age;

        if (!cin)
            throw runtime_error("Age must be a number!");
        if (age < 0 || age > 150)
            throw runtime_error("Invalid age!");

        clearBuffer();
    }

    virtual void show() const
    {
        cout << "Name: " << name << " | Gender: " << gender << " | Age: " << age;
    }
};

class Student : virtual public Human
{
protected:
    int course;
    string group;
    string university;

public:
    Student() : course(0) {}

    virtual void input() override
    {
        Human::input();
        cout << "Enter course: ";
        cin >> course;
        if (!cin)
            throw runtime_error("Course must be a number!");
        clearBuffer();

        cout << "Enter group: ";
        getline(cin, group);
        cout << "Enter university (study): ";
        getline(cin, university);
    }

    virtual void show() const override
    {
        Human::show();
        cout << "\n   [Student] University: " << university
             << ", Course: " << course << ", Group: " << group;
    }
};

class Teacher : virtual public Human
{
protected:
    string university;
    string position;
    double salary;

public:
    Teacher() : salary(0.0) {}

    virtual void input() override
    {
        Human::input();
        cout << "Enter university (work): ";
        getline(cin, university);
        cout << "Enter position: ";
        getline(cin, position);
        cout << "Enter salary: ";
        cin >> salary;
        if (!cin)
            throw runtime_error("Invalid salary!");
        clearBuffer();
    }

    virtual void show() const override
    {
        Human::show();
        cout << "\n   [Teacher] University: " << university
             << ", Position: " << position << ", Salary: " << salary;
    }
};

class Aspirant : public Student, public Teacher
{
public:
    void input() override
    {
        cout << "--- Aspirant Input ---" << endl;
        Human::input();

        cout << "Enter course: ";
        cin >> course;
        clearBuffer();
        cout << "Enter group: ";
        getline(cin, group);

        cout << "Enter position: ";
        getline(cin, position);
        cout << "Enter salary: ";
        cin >> salary;
        clearBuffer();

        string uni;
        cout << "Enter university (shared): ";
        getline(cin, uni);

        Student::university = uni;
        Teacher::university = uni;
    }

    void show() const override
    {
        Human::show();
        cout << "\n   [ASPIRANT]";
        cout << "\n   -> Study: " << Student::university << ", PhD student, gr. " << group;
        cout << "\n   -> Work:  " << Teacher::university << ", " << position;
    }
};

int main()
{
    const int MAX_PEOPLE = 10;
    Human *people[MAX_PEOPLE];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\n--- MENU (" << count << "/" << MAX_PEOPLE << ") ---" << endl;
        cout << "1. Add Student\n2. Add Teacher\n3. Add Aspirant\n4. Show All\n0. Exit\n> ";

        if (!(cin >> choice))
        {
            cin.clear();
            clearBuffer();
            cout << "Invalid input." << endl;
            continue;
        }
        clearBuffer();

        if (choice == 0)
            break;

        if (choice >= 1 && choice <= 3)
        {
            if (count >= MAX_PEOPLE)
            {
                cout << "Array is full!" << endl;
                continue;
            }

            try
            {
                Human *h = nullptr;
                if (choice == 1)
                    h = new Student();
                else if (choice == 2)
                    h = new Teacher();
                else if (choice == 3)
                    h = new Aspirant();

                h->input();
                people[count] = h;
                count++;
                cout << "Successfully added." << endl;
            }
            catch (const exception &e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 4)
        {
            if (count == 0)
                cout << "List is empty." << endl;
            for (int i = 0; i < count; ++i)
            {
                people[i]->show();
                cout << "\n-----------------" << endl;
            }
        }
        else
        {
            cout << "Unknown command." << endl;
        }
    }

    for (int i = 0; i < count; ++i)
    {
        delete people[i];
    }

    return 0;
}