#include <iostream>
using namespace std;

int main()
{ // input
    char a;
    cout << "Enter a character: ";
    cin >> a;

    // output
    cout << "-" << a << "-" << a << "-" << a << endl;
    cout << a << "|" << a << "|" << a << endl;
    cout << "-" << a << "-" << a << "-" << a << endl;

    return 0;
}
