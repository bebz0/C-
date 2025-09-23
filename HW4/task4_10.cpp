#include <iostream>
using namespace std;

int main()
{
    float a = 1.0f;

    while (1.0f + a / 2.0f > 1.0f)
    {
        a /= 2.0f;
    }

    cout << "Machine epsilon (float): " << a << endl;
    return 0;
}
