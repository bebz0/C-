#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool IsEven(int x)
{
    return (x % 2 == 0);
}

bool IsPowerOf3(int x)
{
    if (x < 1)
        return false;
    if (x % 3 == 0)
    {
        x /= 3;
    }
    return x == 1;
}

bool IsPerfectSquare(int x)
{
    if (x < 0)
        return false;
    int a = sqrt(x);
    return a * a == x;
}

bool HasThreeDivisors(int x)
{
    if (x < 4)
        return false;
    int root = sqrt(x);
    if (root * root != x)
        return false; // must be an perfectt square
    int count = 0;
    for (int i = 1; i <= root; i++)
    {
        if (root % i == 0)
            count += 2;
        if (count > 3)
            return false;
    }
    return count == 3; // when the root is a prime number
}
bool IsPalindrome(int x)
{
    if (x < 0)
        return false;
    int orig = x, rev = 0;
    while (x != 0)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return orig == rev;
}
bool IsFibonacci(int x)
{
    if (x < 0)
        return false;
    auto isPerfectSquare = [](int n)
    {
        int s = sqrt(n);
        return s * s == n;
    };
    // n — Fib, if 5n² +- 4 - perfect squzare
    return isPerfectSquare(5 * x * x + 4) || isPerfectSquare(5 * x * x - 4);
}

int main()
{
    ofstream f("F.txt");
    int n;
    cout << "Enter natural numbers (0 - end):\n";
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        f << n << " ";
    }
    f.close();
    ifstream fin("F.txt");
    ofstream g("G.txt");
    while (fin >> n)
    {
        if (IsEven(n))
            g << n << " ";
        if (IsPowerOf3(n))
            g << n << " ";
        if (IsPerfectSquare(n))
            g << n << " ";
        if (HasThreeDivisors(n))
            g << n << " ";
        if (IsPalindrome(n))
            g << n << " ";
        if (IsFibonacci(n))
            g << n << " ";
    }
    fin.close();
    g.close();
    cout << "file G.txt was maded\n";
    return 0;
}