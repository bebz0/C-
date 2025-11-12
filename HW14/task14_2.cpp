#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile.is_open())
    {
        cout << "Can't open input.txt" << endl;
        return 1;
    }
    if (!outputFile.is_open())
    {
        cout << "Can't made output.txt" << endl;
        inputFile.close();
        return 1;
    }
    string currWord;
    string prevWord = "";

    if (inputFile >> currWord)
    {
        outputFile << currWord;
        prevWord = currWord;
    }
    while (inputFile >> currWord)
    {
        if (prevWord == "der" || prevWord == "die" || prevWord == "das")
        {
            if (!currWord.empty())
            {
                char firstChar = currWord[0];
                if (firstChar >= 'a' && firstChar <= 'z')
                {
                    currWord[0] = (char)(firstChar - 32); // convert to upper
                }
            }
        }
        outputFile << " " << currWord;
        prevWord = currWord;
    }

    inputFile.close();
    outputFile.close();
    cout << "Res saved to output.txt" << endl;

    return 0;
}