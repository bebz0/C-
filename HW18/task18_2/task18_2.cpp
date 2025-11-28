#include <iostream>
#include <stack>
#include "MyStack.h"

using namespace std;
//our stack
size_t inputArray(int*& arr) {
    MySpace::Stack<int> myStack;
    int val;
    
    cout << "Enter int (0 - end): ";
    while (cin >> val && val != 0) {
        myStack.push(val);
    }

    size_t size = myStack.size();
    
    if (size > 0) {
        arr = new int[size];


        for (int i = size - 1; i >= 0; i--) {
            arr[i] = myStack.top(); // take top
            myStack.pop();          // delete it
        }
    } else {
        arr = nullptr;
    }

    return size;
}

int main() {
    cout << "Task Implementatio" << endl;
    int* myArray = nullptr;
    size_t count = inputArray(myArray);

    cout << "Array elements (" << count << "): ";
    for (size_t i = 0; i < count; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl << endl;
    delete[] myArray;

    cout << "Our stack vs std::stack" << endl;
    MySpace::Stack<int> myS;
    std::stack<int> stdS;

    myS.push(5); stdS.push(5);
    myS.push(10); stdS.push(10);
    myS.push(50); stdS.push(50);

    cout << "Our stack top: " << myS.top() << " | std::stack top: " << stdS.top() << endl;
    myS.pop(); stdS.pop(); //delette 50

    cout << "MyStack top after pop: " << myS.top() << " | std::stack top after pop: " << stdS.top() << endl;
    cout << "MyStack size: " << myS.size() << " | std::stack size: " << stdS.size() << endl;

    if (myS.top() == stdS.top() && myS.size() == stdS.size()) {
        cout << "Our stack works correctly" << endl;
    } else {
        cout << "Fail :(( " << endl;
    }

    return 0;
}