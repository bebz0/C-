#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void Lower(string &word)
{
    if (word.empty())
    {
        return;
    }
    char &c = word[0];
    if (c >= 'A' && c <= 'Z')
    {
        c = c + 32; // 'a' - 'A' = 32
    }
}

string prV1(const string &s)
{
    stringstream ss(s);
    string currWord;
    string prevWord = "";
    string res = "";

    while (ss >> currWord)
    {
        if (prevWord == "a" || prevWord == "an" || prevWord == "the")
        {
            Lower(currWord);
        }

        if (res.empty())
        {
            res = currWord;
        }
        else
        {
            res += " " + currWord;
        }
        prevWord = currWord;
    }
    return res;
}

void prV2(string &s)
{
    stringstream ss(s);
    string currWord;
    string prevWord = "";
    string res = "";

    while (ss >> currWord)
    {
        if (prevWord == "a" || prevWord == "an" || prevWord == "the")
        {
            Lower(currWord);
        }

        if (res.empty())
        {
            res = currWord;
        }
        else
        {
            res += " " + currWord;
        }

        prevWord = currWord;
    }
    s = res;
}

int main()
{
    string Inp;

    cout << "Enter a sentence: ";
    getline(cin, Inp);

    cout << "\nVar 1 (returns new string)" << endl;
    string s1 = Inp;
    string res_v1 = prV1(s1);
    cout << "Orig: '" << s1 << "'" << endl;
    cout << "Res:   '" << res_v1 << "'" << endl;
    cout << "\nVar 2 (modifies in place)" << endl;
    string s2 = Inp;
    cout << "Orig: '" << s2 << "'" << endl;
    prV2(s2);
    cout << "Res:   '" << s2 << "'" << endl;
    return 0;
}