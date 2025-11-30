#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class MyFunction {
    double a, b;

public:
    void set_interval(double x1, double x2) {
        a = x1;
        b = x2;
    }

    double f(double x) {
        return pow(x, 2) + cos(x) + sqrt(x) + log(x);
    }

    double left_rect(int n) {
        double h = (b - a) / n;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += f(a + i * h);
        }
        return sum * h;
    }

    double right_rect(int n) {
        double h = (b - a) / n;
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += f(a + i * h);
        }
        return sum * h;
    }

    double mid_rect(int n) {
        double h = (b - a) / n;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += f(a + i * h + h / 2.0);
        }
        return sum * h;
    }

    double trapezoid(int n) {
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        for (int i = 1; i < n; i++) {
            sum += 2 * f(a + i * h);
        }
        return sum * h / 2.0;
    }

    double simpson(int n) {
        if (n % 2 != 0) n++; 
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        
        for (int i = 1; i < n; i++) {
            if (i % 2 != 0) {
                sum += 4 * f(a + i * h);
            } else {
                sum += 2 * f(a + i * h);
            }
        }
        return sum * h / 3.0;
    }

    void show_table(int count) {
        if (count < 2) count = 2;
        double h = (b - a) / (count - 1);
        
        cout << endl << "Table of values:" << endl;
        cout << "X \t\t F(X)" << endl;
        
        for (int i = 0; i < count; i++) {
            double x = a + i * h;
            cout << fixed << setprecision(4) << x << " \t " << f(x) << endl;
        }
    }
};

int main() {
    MyFunction obj;
    double a, b;
    int n, k;

    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    obj.set_interval(a, b);

    cout << "Enter steps (N): ";
    cin >> n;

    cout << "Left Rect:   " << obj.left_rect(n) << endl;
    cout << "Right Rect:  " << obj.right_rect(n) << endl;
    cout << "Mid Rect:    " << obj.mid_rect(n) << endl;
    cout << "Trapezoid:   " << obj.trapezoid(n) << endl;
    cout << "Simpson:     " << obj.simpson(n) << endl;

    cout << "Enter samples count: ";
    cin >> k;
    obj.show_table(k);

    return 0;
}