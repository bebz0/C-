#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string filename;
    cout << "Enter the filename to check: ";
    cin >> filename;
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Can't open '" << filename << "'" << endl;
        return 1;
    }
    stringstream bufer;
    bufer << fin.rdbuf();
    string content = bufer.str();
    fin.close();

    int count = 0;
    size_t head = 0;
    const string openTag = "<td>";
    const string closeTag = "</td>";
    while (true)
    {
        size_t headOpen = content.find(openTag, head);
        size_t headClose = content.find(closeTag, head);

        if (headClose == string::npos && headOpen == string::npos)
        {
            break;
        }
        if (headOpen != string::npos && (headOpen < headClose))
        {
            count++;
            head = headOpen + openTag.length();
        }
        else if (headClose != string::npos)
        {
            count--;
            head = headClose + closeTag.length();
        }

        if (count < 0)
        {
            cerr << "Found a closing tag for which there wasn't opening tag" << endl;
            return 1;
        }
    }

    if (count == 0)
    {
        cout << "check is successful" << endl;
    }
    else
    {
        cerr << "NNot enough " << count
             << "</td>" << endl;
    }
    return 0;
}