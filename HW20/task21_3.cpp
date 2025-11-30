#include <iostream>
#include <vector>

using namespace std;

long long get_sum_largest(vector<int> arr, int k) {
    if (k > arr.size()) {
        return 0;
    }

    int n = arr.size();
    // Bubble sort (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    return sum;
}

vector<int> get_smallest_array(vector<int> arr, int k) {
    if (k > arr.size()) {
        return {};
    }

    int n = arr.size();
    // Bubble sort (ascending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(arr[i]);
    }
    return res;
}

int main() {
    int n;
    cout << "Enter vector size: ";

    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;
    long long sum_res = get_sum_largest(nums, k);

    if (sum_res == 0 && k > n) {
        cout << "Error: k is too large" << endl;
    } else {
        cout << "Sum of " << k << " largest: " << sum_res << endl;
    }

    vector<int> small_res = get_smallest_array(nums, k);

    if (small_res.empty() && k > n) {
        cout << "Error: k is too large (cannot return array)." << endl;
    } else {
        cout << k << " smallest numbers: ";
        for (int x : small_res) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}