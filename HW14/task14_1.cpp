#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cout << "Can't open input.txt" << endl;
        return 1;
    }

    double res = 0.0;
    double currNum;
    char oper;
    if (!(inputFile >> res))
    {
        cout << "File is empty or has invlid data" << endl;
        inputFile.close();
        return 1;
    }
    while (inputFile >> oper)
    {
        if (oper == '=')
        {
            break;
        }
        if (!(inputFile >> currNum))
        {
            cout << "Expected a number after the operator '" << oper << "'" << endl;
            inputFile.close();
            return 1;
        }
        if (oper == '+')
        {
            res += currNum;
        }
        else if (oper == '-')
        {
            res -= currNum;
        }
        else
        {
            cerr << "Invalid operator '" << oper << "'" << endl;
        }
    }
    inputFile.close();
    cout << "Res: " << res << endl;
    return 0;
}