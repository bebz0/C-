#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define N 100
#define DEFAULT_FILENAME "phonebook.txt"

class Person
{
protected:
    string name;
    unsigned byear;

public:
    Person() : name(""), byear(0) {}
    Person(string name_, unsigned byear_) : name(name_), byear(byear_) {}
    virtual int input();
    virtual void show() const;

    string get_name() const { return name; }
    friend ostream &operator<<(ostream &os, const Person &p);
    friend istream &operator>>(istream &is, Person &p);
};

class Friend : public Person
{
    string phone;

public:
    Friend() : Person(), phone("") {}
    Friend(string name_, unsigned byear_, string phone_) : Person(name_, byear_), phone(phone_) {}

    string get_phone() const { return phone; }
    void set_phone(string phone_) { phone = phone_; }

    int input() override;
    void show() const override;

    friend ostream &operator<<(ostream &os, const Friend &f);
    friend istream &operator>>(istream &is, Friend &f);
};

class Phonebook
{
    unsigned n;
    Friend data[N];
    string filename;

public:
    Phonebook(string fname = DEFAULT_FILENAME) : n(0), filename(fname)
    {
        load_from_file();
    }

    ~Phonebook()
    {
        save_to_file();
    }

    void add_Friend(const Friend &f);
    string search_phone(string name) const;

    bool update_phone(string name, string new_phone);

    void save_to_file() const;
    void load_from_file();
};

int Person::input()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter birth year: ";
    cin >> byear;
    return 0;
}

void Person::show() const
{
    cout << "Name: " << name << endl;
    cout << "Birthday: " << byear << endl;
}

ostream &operator<<(ostream &os, const Person &p)
{

    os << p.name << " " << p.byear;
    return os;
}

istream &operator>>(istream &is, Person &p)
{
    is >> p.name >> p.byear;
    return is;
}

int Friend::input()
{
    Person::input();
    cout << "Enter phone number: ";
    cin >> phone;
    return 0;
}

void Friend::show() const
{
    Person::show();
    cout << "Phone: " << phone << endl;
}

ostream &operator<<(ostream &os, const Friend &f)
{
    os << (const Person &)f << " " << f.phone;
    return os;
}

istream &operator>>(istream &is, Friend &f)
{
    is >> (Person &)f >> f.phone;
    return is;
}

void Phonebook::add_Friend(const Friend &f)
{
    if (n < N)
    {
        data[n] = f;
        n++;
        cout << "Friend added." << endl;
    }
    else
    {
        cout << "Phonebook is full!" << endl;
    }
}

string Phonebook::search_phone(string name) const
{
    for (unsigned i = 0; i < n; i++)
    {
        if (data[i].get_name() == name)
            return data[i].get_phone();
    }
    return "Not found";
}

bool Phonebook::update_phone(string name, string new_phone)
{
    for (unsigned i = 0; i < n; i++)
    {
        if (data[i].get_name() == name)
        {
            data[i].set_phone(new_phone);
            cout << "Phone number updated for " << name << "." << endl;
            return true;
        }
    }
    cout << "Name not found, cannot update." << endl;
    return false;
}

void Phonebook::save_to_file() const
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cout << "Error: Can]t save to file " << filename << endl;
        return;
    }

    fout << n << endl;
    for (unsigned i = 0; i < n; i++)
    {
        fout << data[i] << endl;
    }
    fout.close();
    cout << "Phonebook saved to " << filename << endl;
}

void Phonebook::load_from_file()
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << "File not found.Starting with an empty phonebook." << endl;
        return;
    }

    int count = 0;
    fin >> count;
    fin.ignore();
    if (count > N)
        count = N;

    n = 0;
    for (int i = 0; i < count; i++)
    {
        Friend temp;
        fin >> temp;
        if (fin.good())
        {
            add_Friend(temp);
        }
    }
    fin.close();
    cout << "Loaded " << n << " friends from " << filename << endl;
}

int main()
{
    Phonebook p;
    int choice = 0;
    while (choice != 5)
    {
        cout << "\n Phonebook Menu" << endl;
        cout << "1. Add Friend" << endl;
        cout << "2. Search Phone" << endl;
        cout << "3. Update Phone" << endl;
        cout << "4. Show All (using overloaded <<)" << endl;
        cout << "5. Save & Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Friend f;
            f.input();
            p.add_Friend(f);
        }
        else if (choice == 2)
        {
            string search_name;
            cout << "Enter name to search phone: ";
            cin >> search_name;
            cout << "Phone number: " << p.search_phone(search_name) << endl;
        }
        else if (choice == 3)
        {
            string name, new_phone;
            cout << "Enter name to update: ";
            cin >> name;
            cout << "Enter new phone number: ";
            cin >> new_phone;
            p.update_phone(name, new_phone);
        }
        else if (choice == 4)
        {
            Friend test("ROma", 2006, "12345");
            cout << "\nTest output for one Friend " << endl;
            cout << test << endl;
        }
    }
    return 0;
}