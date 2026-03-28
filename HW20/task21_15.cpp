#include <iostream>
#include <vector>
#include <algorithm> // for_each, generate
#include <numeric>   // partial_sum
#include <functional> // multiplies

using namespace std;

class B {
public:
    virtual void f() {
        cout << "B sf ()" << endl;
    }
    virtual ~B() {} 
};

class D : public B {
public:
    void f() override {
        cout << "Derived message from D" << endl;
    }
};

void run_f(B* obj) {
    obj->f();
}

struct NumberGenerator {
    int current = 0;
    int operator()() {
        return ++current;
    }
};

int main() {
    vector<B*> my_vector;
    my_vector.push_back(new B());
    my_vector.push_back(new D());
    my_vector.push_back(new B());

    for_each(my_vector.begin(), my_vector.end(), run_f);

    for (size_t i = 0; i < my_vector.size(); i++) {
        delete my_vector[i];
    }

    cout << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> numbers(n);
    generate(numbers.begin(), numbers.end(), NumberGenerator());
    vector<long long> facts(n);
    partial_sum(numbers.begin(), numbers.end(), facts.begin(), multiplies<long long>());
    cout << "Factorial table:" << endl;
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << "! = " << facts[i] << endl;
    }

    return 0;
}