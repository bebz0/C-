#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string rmV1(const string &s)
{
    string res = "";
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (isspace(s[i]))
        {
            res += s[i];
        }
        else
        {
            size_t j = i;
            while (j < s.length() && !isspace(s[j]))
            {
                j++;
            }

            size_t lenWord = j - i;

            if (lenWord > 0)
            {

                res.append(s, i, lenWord - 1);
            }
            i = j - 1;
        }
    }
    return res;
}

void rmV2(string &s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!isspace(s[i]))
        {
            size_t j = i;
            while (j < s.length() && !isspace(s[j]))
            {
                j++;
            }
            if (j > i)
            {
                s.erase(j - 1, 1);
            }
            i = j - 2;
        }
    }
}

int main()
{
    string Inp;

    cout << "Enter a string: ";
    getline(cin, Inp);
    cout << "\nVar 1 (returns new string)" << endl;
    string s1 = Inp;
    string res_v1 = rmV1(s1);
    cout << "Orig: '" << s1 << "'" << endl;
    cout << "res:   '" << res_v1 << "'" << endl;

    cout << "\nVar 2 (modifies in place)" << endl;
    string s2 = Inp;
    cout << "Orig: '" << s2 << "'" << endl;
    rmV2(s2);
    cout << "Res:   '" << s2 << "'" << endl;
    return 0;
}