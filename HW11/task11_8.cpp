#include <iostream>
#include <fstream>
using namespace std;

static const int N = 1000;

int main()
{
    ifstream fin("F.txt");
    ofstream fout("G.txt");
    if (!fin || !fout)
    {
        cout << "Can't open files" << endl;
        return 1;
    }

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[N];
    int k = 0, num;
    while (fin >> num)
    {
        arr[k++] = num;
    }

    int i = 0;
    while (i < k)
    {
        int maxx = arr[i];
        int j = i + 1;
        while (j < i + n && j < k)
        {
            if (arr[j] > maxx)
                maxx = arr[j];
            j++;
        }
        fout << maxx << " ";
        i += n;
    }

    cout << "File G.txt was maded'" << endl;

    fin.close();
    fout.close();

    return 0;
}
