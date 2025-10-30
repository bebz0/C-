#include <iostream>
#include <fstream>
using namespace std;

static const int N = 100;
// Task 11_12 (a)
struct Toy
{
    char name[50];
    int price;
    int minAge;
    int maxAge;
};
void createSampleFile(const char *filename)
{
    ifstream fcheck(filename);
    if (fcheck)
    {
        fcheck.close();
        return;
    }

    Toy toys[5] = {
        {"Ball", 120, 2, 8},
        {"Doll", 250, 3, 10},
        {"Driver's license", 400, 16, 80},
        {"Cigarettes", 180, 18, 90},
        {"Educational toy", 90, 0, 3}};

    ofstream fout(filename);
    if (!fout)
    {
        cout << "Error creating file " << filename << endl;
        return;
    }

    for (int i = 0; i < 5; i++)
        fout.write((char *)&toys[i], sizeof(Toy));

    fout.close();
    cout << "Sample file " << filename << " created\n";
}

int readAllToys(const char *filename, Toy arr[], int maxCount)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "Cant open " << filename << endl;
        return 0;
    }
    int c = 0;
    while (fin.read((char *)&arr[c], sizeof(Toy)))
    {
        c++;
        if (c >= maxCount)
        {
            break;
        }
    }
    fin.close();
    return c;
}

void showFileContent(const char *filename)
{
    Toy toys[N];
    int count = readAllToys(filename, toys, N);

    cout << "\nFile '" << filename << "' content:\n";
    if (count == 0)
    {
        cout << "(empty)\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << toys[i].name << "  "
             << "Price: " << toys[i].price
             << " Age: [" << toys[i].minAge << "," << toys[i].maxAge << "]\n";
    }
}

void searchAndSave(Toy toys[], int count, int maxPrice, int age, const char *outFile)
{
    ofstream fout(outFile);
    if (!fout)
    {
        cout << "Error writing file " << outFile << endl;
        return;
    }

    bool any = false;
    cout << "\nMatching toys:\n";
    for (int i = 0; i < count; i++)
    {
        if (toys[i].price <= maxPrice && age >= toys[i].minAge && age <= toys[i].maxAge)
        {
            cout << toys[i].name << "  " << toys[i].price
                 << "  Age: [" << toys[i].minAge << "," << toys[i].maxAge << "]\n";
            fout.write((char *)&toys[i], sizeof(Toy));
            any = true;
        }
    }
    if (!any)
        cout << "No matches((\n";

    fout.close();
    cout << "Result saved to " << outFile << "\n";
}

int main()
{
    const char *file = "toys.bin";
    const char *out = "result.bin";

    createSampleFile(file);

    Toy arr[N];
    int n = readAllToys(file, arr, N);
    if (!n)
    {
        cout << "File empty or unreadble\n";
        return 1;
    }
    showFileContent(file);
    int price, age;
    cout << "\nEnter max price: ";
    cin >> price;
    cout << "Enter age: ";
    cin >> age;
    searchAndSave(arr, n, price, age, out);
    showFileContent(out);
    return 0;
}
