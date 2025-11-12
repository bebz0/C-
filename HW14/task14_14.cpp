#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createTestFiles()
{
    ofstream fout1("Name1.txt");
    fout1 << "Line 1 from file 1" << endl;
    fout1 << "Line 2 from file 1" << endl;
    fout1 << "Line 3 from file 1" << endl;
    fout1 << "Line 4 from file 1" << endl;
    fout1 << "Line 5 from file 1" << endl;
    fout1.close();

    ofstream fout2("Name2.txt");
    fout2 << " (appended line A)";
    fout2 << " (appended line B)";
    fout2 << " (appended line C)";
    fout2.close();

    cout << "Test files 'Name1.txt' and 'Name2.txt' were created" << endl;
}

void merge(const string &file1, const string &file2, const string &output)
{
    ifstream fin1(file1);
    ifstream fin2(file2);
    ofstream fout(output);
    if (!fin1.is_open())
    {
        cerr << "Can't open '" << file1 << "'" << endl;
        return;
    }
    if (!fin2.is_open())
    {
        cerr << "Cann't open '" << file2 << "'" << endl;
        return;
    }
    if (!fout.is_open())
    {
        cerr << "Can't create '" << output << "'" << endl;
        return;
    }

    string line1, line2;
    while (getline(fin1, line1))
    {
        if (!getline(fin2, line2))
        {
            fin2.clear();
            fin2.seekg(0, ios::beg);
            if (!getline(fin2, line2))
            { // if file 2empty
                line2 = "";
            }
        }
        fout << line1 << line2 << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();

    cout << "Files merged successfully into " << output << endl;
}

int main()
{
    createTestFiles();

    merge("Name1.txt", "Name2.txt", "Output.txt");

    cout << "\nRes in 'Output.txt'" << endl;

    return 0;
}