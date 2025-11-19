#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
static const int N = 5;

void createTestFile(const string &filename, int N)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cerr << "Can't create file " << filename << endl;
        return;
    }

    string data[] = {
        "Poschtak 2 2 5,5,4,5",
        "Kudermin 2 2 5,5,5,4",
        "Batrak 2 1 5,4,4,5",
        "Brazhnik 4 2 3,3,3,2",
        "Kolesnikov 4 2 5,5,5,5"};

    for (int i = 0; i < N; ++i)
    {
        fout << data[i % 5] << endl;
    }
    fout.close();
    cout << "Test file '" << filename << "' created" << endl;
}

string findWorstStudent(const string &filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Can't open file " << filename << endl;
        return "ERROR";
    }

    string line;
    string worstSt;

    double minAvg = 0.0;
    bool firstSt = true;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        string surname;
        int course, group;
        string grades;
        ss >> surname >> course >> group;
        getline(ss >> ws, grades);

        stringstream gradeStream(grades);
        string singleGradeStr;
        double sum = 0;
        int count = 0;

        while (getline(gradeStream, singleGradeStr, ','))
        {
            int grade = 0;
            stringstream converter(singleGradeStr);
            if (converter >> grade)
            {
                sum += grade;
                count++;
            }
        }

        if (count > 0)
        {
            double avg = sum / count;
            if (firstSt)
            {
                minAvg = avg;
                worstSt = surname;
                firstSt = false;
            }
            else if (avg < minAvg)
            {
                minAvg = avg;
                worstSt = surname;
            }
        }
    }

    fin.close();
    return worstSt;
}

int main()
{
    const string FILENAME = "students.txt";
    createTestFile(FILENAME, N);

    string worstStudent = findWorstStudent(FILENAME);

    if (worstStudent != "ERROR")
    {
        cout << "\nStudent with the worst avg grade: " << worstStudent << endl;
    }

    return 0;
}