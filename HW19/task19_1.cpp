#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cout << "Enter number of buyers: ";
    std::cin >> n;

    std::vector<double> t(n);
    std::cout << "Enter service times t1 ... tn:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "t[" << i+1 << "]: ";
        std::cin >> t[i];
    }

    std::vector<double> c(n);
    double finish = 0.0;

    for (int i = 0; i < n; ++i) {
        double arrival = (double)i;

        double start;
        if (arrival > finish)
            start = arrival;
        else
            start = finish;

        c[i] = start - arrival;
        finish = start + t[i];
    }

    int idx_min_t = 0;
    for (int i = 1; i < n; ++i) {
        if (t[i] < t[idx_min_t]) {
            idx_min_t = i;
        }
    }

    int idx_max_c = 0;
    for (int i = 1; i < n; ++i) {
        if (c[i] > c[idx_max_c]) {
            idx_max_c = i;
        }
    }

    std::cout << "\nWaiting times c[i]:\n";
    std::cout << std::fixed << std::setprecision(6);
    for (int i = 0; i < n; ++i) {
        std::cout << "c[" << (i+1) << "] = " << c[i] << "\n";
    }

    std::cout << "\nBuyer with minimum service time: " << (idx_min_t + 1) << "\n";
    std::cout << "Buyer who waited the longest: " << (idx_max_c + 1) << "\n";

    return 0;
}
