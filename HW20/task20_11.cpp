#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    string fname;
    cout << "Enter filename: ";
    cin >> fname;

    int n;
    cout << "Enter vector size (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error: Size must be even" << endl;
        return 1;
    }

    vector<int> v(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int half = n / 2;
    vector<int> part1, part2;

    for (int i = 0; i < half; i++) {
        part1.push_back(v[i]);
    }
    for (int i = half; i < n; i++) {
        part2.push_back(v[i]);
    }

    sort(part1.begin(), part1.end());
    auto last1 = unique(part1.begin(), part1.end());
    part1.erase(last1, part1.end());

    sort(part2.begin(), part2.end());
    auto last2 = unique(part2.begin(), part2.end());
    part2.erase(last2, part2.end());

    vector<int> result;

    set_difference(part2.begin(), part2.end(), 
                   part1.begin(), part1.end(), 
                   back_inserter(result));

    ofstream out(fname);
    if (out.is_open()) {
        for (int x : result) {
            out << x << endl;
        }
        out.close();
        cout << "Done. Results saved to " << fname << endl;
    } else {
        cout << "Error opening file" << endl;
    }

    return 0;
}