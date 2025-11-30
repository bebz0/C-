#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    ofstream f("text_data.txt");
    f << "Hello world! Hello Borodin" << endl;
    f << "Kanye West. Kanye West." << endl;
    f.close();

    ifstream fin("text_data.txt");
    if (!fin.is_open()) {
        cout << "File not found." << endl;
        return 1;
    }

    map<string, int> data;
    string word = "";
    char c;

    while (fin.get(c)) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                data[word]++;
                word = "";
            }
        }
    }

    if (!word.empty()) {
        data[word]++;
    }

    fin.close();

    cout << "Word counts:" << endl;
    for (auto const& pair : data) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}