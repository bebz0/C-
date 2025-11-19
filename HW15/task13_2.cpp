#include <iostream>
#include <string>
using namespace std;
string prV1(const string &s)
{
    size_t pos_first = s.find('.');
    size_t pos_last = s.rfind('.');
    if (pos_first == string::npos)
    {
        size_t char_first = s.find_first_not_of(" \t");

        if (char_first == string::npos)
        {
            return "";
        }
        return s.substr(char_first);
    }

    if (pos_first == pos_last)
    {
        return s.substr(pos_first);
    }

    string pt1 = s.substr(0, pos_first + 1);
    string pt2 = s.substr(pos_last);
    return pt1 + pt2;
}

void prV2(string &s)
{
    size_t pos_first = s.find('.');
    size_t pos_last = s.rfind('.');
    if (pos_first == string::npos)
    {
        size_t char_first = s.find_first_not_of(" \t");
        if (char_first == string::npos)
        {
            s.clear(); // s = ""
        }
        else
        {
            s = s.substr(char_first);
        }
        return;
    }
    if (pos_first == pos_last)
    {
        s = s.substr(pos_first);
        return;
    }
    size_t start_pos = pos_first + 1;
    size_t count = pos_last - start_pos;
    s.erase(start_pos, count);
}

int main()
{
    string Inp;
    cout << "Enter a string: ";
    getline(cin, Inp);

    cout << "\nVar 1 (returns new string)" << endl;
    string s1 = Inp;
    string result_v1 = prV1(s1);
    cout << "Orig: '" << s1 << "'" << endl;
    cout << "Res: '" << result_v1 << "'" << endl;

    cout << "\nVar 2 (modifies in place)" << endl;
    string s2 = Inp;
    cout << "Orig: '" << s2 << "'" << endl;
    prV2(s2);
    cout << "Res: '" << s2 << "'" << endl;
    return 0;
}