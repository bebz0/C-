#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

typedef unsigned char UCHAR;

int to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char to_char(int v) {
    if (v >= 0 && v <= 9) return (char)(v + '0');
    if (v >= 10 && v <= 35) return (char)(v - 10 + 'A');
    return '?';
}

vector<int> addition(const vector<UCHAR>& A, int baseA, const vector<UCHAR>& B, int baseB, int baseResult) {
    if (baseA < 2 || baseB < 2 || baseResult < 2) return {};

    unsigned long long numA = 0;
    unsigned long long p = 1;
    
    for (int i = A.size() - 1; i >= 0; i--) {
        int val = to_int(A[i]);
        if (val == -1 || val >= baseA) return {};
        numA += val * p;
        p *= baseA;
    }

    unsigned long long numB = 0;
    p = 1;
    for (int i = B.size() - 1; i >= 0; i--) {
        int val = to_int(B[i]);
        if (val == -1 || val >= baseB) return {};
        numB += val * p;
        p *= baseB;
    }

    unsigned long long sum = numA + numB;

    if (sum == 0) return {0};

    vector<int> res;
    while (sum > 0) {
        res.push_back(sum % baseResult);
        sum /= baseResult;
    }

    int n = res.size();
    for (int i = 0; i < n / 2; i++) {
        int temp = res[i];
        res[i] = res[n - 1 - i];
        res[n - 1 - i] = temp;
    }

    return res;
}

bool parse_line(string line, int &base, vector<UCHAR> &vec) {
    vec.clear();
    size_t colon = line.find(':');
    if (colon == string::npos) return false;

    try {
        base = stoi(line.substr(0, colon));
    } catch (...) {
        return false;
    }

    size_t q1 = line.find('"', colon);
    size_t q2 = line.rfind('"');

    if (q1 == string::npos || q2 == string::npos || q1 == q2) return false;

    string s = line.substr(q1 + 1, q2 - q1 - 1);
    for (char c : s) {
        vec.push_back((UCHAR)c);
    }
    return true;
}

void run_tests() {
    cout << "Running tests" << endl;
    
    vector<UCHAR> a = {'1', '0'};
    vector<UCHAR> b = {'1', '0'};
    vector<int> res = addition(a, 10, b, 10, 10);
    
    if (res.size() == 2 && res[0] == 2 && res[1] == 0) 
        cout << "Test 1: OK" << endl;
    else 
        cout << "Test 1: FAIL" << endl;

    a = {'F'};
    b = {'1'};
    res = addition(a, 16, b, 16, 2);
    
    if (res.size() == 5 && res[0] == 1) 
        cout << "Test 2: OK" << endl;
    else 
        cout << "Test 2: FAIL" << endl;

    a = {'Z'}; 
    res = addition(a, 10, b, 10, 10);
    if (res.empty()) 
        cout << "Test 3: OK" << endl;
    else 
        cout << "Test 3: FAIL" << endl;
        
    cout << "----------------" << endl;
}

int main() {
    run_tests();

    string ifname = "input.txt";
    string ofname = "output.txt";

    ofstream tmp(ifname);
    tmp << "16: \"FD\"" << endl;
    tmp << "10: \"253\"" << endl;
    tmp.close();

    ifstream in(ifname);
    if (!in.is_open()) {
        cout << "Can't open input file" << endl;
        return 1;
    }

    string l1, l2;
    if (!getline(in, l1) || !getline(in, l2)) {
        cout << "File is empty or invalid" << endl;
        return 1;
    }
    in.close();

    int b1, b2, b_res;
    vector<UCHAR> v1, v2;

    if (!parse_line(l1, b1, v1) || !parse_line(l2, b2, v2)) {
        cout << "Format error" << endl;
        return 1;
    }

    cout << "Enter target base: ";
    cin >> b_res;

    vector<int> result = addition(v1, b1, v2, b2, b_res);

    ofstream out(ofname);
    if (result.empty()) {
        cout << "Calculation error" << endl;
        out << "Error";
    } else {
        cout << "Result saved to " << ofname << endl;
        out << "\"";
        for (int x : result) {
            out << to_char(x);
        }
        out << "\"";
    }
    out.close();

    return 0;
}