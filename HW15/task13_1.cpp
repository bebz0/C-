#include <iostream>
#include <string>
using namespace std;
string getV1(const string &s)
{
    size_t pos_col = s.find(':');

    if (pos_col == string::npos)
    {
        return s;
    }
    size_t pos_comma = s.find(',', pos_col);
    if (pos_comma == string::npos)
    {
        return s.substr(pos_col + 1);
    }
    size_t start = pos_col + 1;
    size_t length = pos_comma - start;
    return s.substr(start, length);
}

void getV2(string &s)
{
    size_t pos_col = s.find(':');
    if (pos_col == string::npos)
    {
        return;
    }
    size_t pos_comma = s.find(',', pos_col);
    if (pos_comma == string::npos)
    {
        s = s.substr(pos_col + 1);
        return;
    }
    size_t start = pos_col + 1;
    size_t length = pos_comma - start;
    s = s.substr(start, length);
}

int main()
{
    string Inp;

    cout << "Enter a string: ";
    getline(cin, Inp);

    cout << "\n-Var 1 (returns new string)" << endl;
    string s1 = Inp;
    string res_v1 = getV1(s1);

    cout << "Orig: '" << s1 << "'" << endl;
    cout << "Res:   '" << res_v1 << "'" << endl;
    cout << "Origi is unchanged" << endl;

    cout << "\nVar 2 (modifies in place)" << endl;
    string s2 = Inp;

    cout << "Orig: '" << s2 << "'" << endl;
    getV2(s2);
    cout << "Res:   '" << s2 << "'" << endl;
    cout << "Orig string was modified" << endl;
    return 0;
}