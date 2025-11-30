#include <iostream>
#include <vector>
#include <list>

using namespace std;

int get_max(list<int> row) {
    int mx = row.front();
    for (int x : row) {
        if (x > mx) {
            mx = x;
        }
    }
    return mx;
}

int main() {
    int n, m;
    cout << "Enter n and m (must be < 100): ";
    cin >> n >> m;
    if (n >= 100 || m >= 100) {
        cout << "Error: n and m must be less than 100!" << endl;
        return 1; 
    }
    vector<list<int>> arr;

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        list<int> row;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            row.push_back(num);
        }
        arr.push_back(row);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int max1 = get_max(arr[j]);
            int max2 = get_max(arr[j + 1]);

            if (max1 < max2) {
                list<int> temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << endl << "Sorted matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int x : arr[i]) {
            cout << x << "\t";
        }
        cout << endl;
    }

    return 0;
}