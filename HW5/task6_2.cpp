#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter n, k : ";
    cin >> n >> k;
    int result = n | (1 << k);
    cout << result << endl;
    return 0;
}
