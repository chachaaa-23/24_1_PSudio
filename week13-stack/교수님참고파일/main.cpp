#include "stackInt.h"
#include <iostream>
using namespace std;

int main() {

    int A[] = { 1, 3, 5, 7, 9 };
    MyStackInt myStack(sizeof(A) / sizeof(A[0]));

    myStack.display();
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        myStack.push(A[i]);
        myStack.display();
    }
    myStack.push(100);

    cout << "Stack full: " << myStack.isFull() << endl;
    cout << "Top element: " << myStack.stackTop() << endl;

    cout << "Popped out elements: ";
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << myStack.pop() << " ";
    }
    cout << endl;

    myStack.pop();
    myStack.display();

    cout << "Stack full: " << myStack.isFull() << endl;
    cout << "Stack empty: " << myStack.isEmpty() << endl;

    return 0;
}