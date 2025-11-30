#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int d, n;
    cout << "Enter vector dimension d: ";
    cin >> d;
    cout << "Enter number of vectors n: ";
    cin >> n;

    vector<double> v(d);
    double sum_norms = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "\nInput vector #" << (i + 1) << " (" << d << " values): ";

        for (int j = 0; j < d; j++) {
            cin >> v[j];
        }

        // compute norm
        double s = 0.0;
        for (int j = 0; j < d; j++) {
            s += v[j] * v[j];
        }
        double norm = sqrt(s);

        sum_norms += norm;
    }

    cout << fixed << setprecision(6);
    cout << "\nSum of vector norms: " << sum_norms << "\n";

    return 0;
}
