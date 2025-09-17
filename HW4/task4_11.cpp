#include <iostream>
#include <cmath> // for exp, log
using namespace std;

int main()
{
    cout << "Enter real numbers (0 to stop):" << endl;
    double x, sum = 0.0;
    int index = 0;

    while (true)
    {
        cout << "a[" << index << "]= ";
        cin >> x;
        if (x == 0.0)
            break;
        sum += x;
        index++;
    }

    cout << "Sum of entered numbers = " << sum << endl;

    cout << "\nEnter non-zero integers (0 to stop):" << endl;
    int y, count = 0;
    long long sum_int = 0;
    double log_sum = 0.0; // for geometric mean

    while (true)
    {
        cin >> y;
        if (y == 0)
            break;
        sum_int += y;
        if (y > 0)
        { // geom mean defined only for >0
            log_sum += log((double)y);
        }
        else
        {
            cout << "Geome mean is undefined" << endl;
            return 0;
        }
        count++;
    }

    if (count > 0)
    {
        double mean_arith = (double)sum_int / count;
        double mean_geom = exp(log_sum / count);

        cout << "Arithmetic mean = " << mean_arith << endl;
        cout << "Geometric mean = " << mean_geom << endl;
    }
    else
    {
        cout << "No numbers were entered!" << endl;
        return 1;
    }

    return 0;
}
