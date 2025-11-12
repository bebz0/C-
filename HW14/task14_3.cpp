#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isSep(char c)
{
    if (c == ',' || c == '.' || c == '!' || c == '?')
    {
        return true;
    }
    if (c == ' ' || c == '\n' || c == '\t' || c == '\r')
    {
        return true;
    }

    return false;
}
void reverse(string &s)
{
    if (s.empty())
    {
        return;
    }
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
void Decryptor(const string &inputfile, const string &outputfile)
{
    ifstream fin(inputfile);
    ofstream fout(outputfile);
    if (!fin.is_open())
    {
        cerr << "Can't open file '" << inputfile << "'" << endl;
        return;
    }
    if (!fout.is_open())
    {
        cerr << "Can't made : '" << outputfile << "'" << endl;
        fin.close();
        return;
    }
    string currWord;
    char c;
    while (fin.get(c))
    {
        if (isSep(c))
        {
            if (!currWord.empty())
            {
                reverse(currWord);
                fout << currWord;
                currWord.clear();
            }
            fout << c;
        }
        else
        {
            currWord += c;
        }
    }

    if (!currWord.empty())
    {
        reverse(currWord);
        fout << currWord;
    }

    fin.close();
    fout.close();

    cout << "File wassuccessfully decrypted" << endl;
}

int main()
{
    string inputfile, outputfile;
    cout << "Enter input file name: ";
    cin >> inputfile;
    cout << "Enter output file name: ";
    cin >> outputfile;
    Decryptor(inputfile, outputfile);
    return 0;
}