#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cout << "Enter list size: ";
    cin >> n;

    list<int> nums;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int x;
    cout << "Enter X: ";
    cin >> x;

    list<int>::iterator it = nums.begin();
    int count = 0;

    while (count < n) {
        if (*it > x) {
            list<int>::iterator current = it; 
            it++;
            nums.splice(nums.end(), nums, current);
        } else {
            it++;
        }
        count++;
    }
    cout << "Reordered list: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}