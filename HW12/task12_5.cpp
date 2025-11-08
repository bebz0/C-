#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const string INPUT_FILENAME = "input.txt";
static const int N = 20000;

int main()
{
    unsigned long long numbers[N];
    int count = 0;
    ifstream inFile(INPUT_FILENAME);
    if (!inFile.is_open())
    {
        cerr << "Can't open " << INPUT_FILENAME << endl;
        return 1;
    }

    unsigned long long currentNumber;
    while (inFile >> currentNumber)
    {
        if (count >= N)
        {
            cerr << "lim of "
                 << N << " numbers" << endl;
            cerr << "do only the first " << N << " numbers" << endl;
            break;
        }
        numbers[count] = currentNumber;
        count++;
    }
    inFile.close();
    cout << fixed << setprecision(3);
    cout << "Output:" << endl;
    for (int i = count - 1; i >= 0; --i)
    {
        double root = sqrt(static_cast<double>(numbers[i]));
        cout << root << endl;
    }

    return 0;
}