#include "queueIntList.h"
#include <iostream>
using namespace std;

int main() {

    int A[] = { 1, 3, 5, 7, 9 };
    MyQueueIntList myQueue;

    myQueue.display();
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        myQueue.enqueue(A[i]);
        myQueue.display();
    }

    cout << "Deleting elements: ";
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << myQueue.dequeue() << " ";
    }
    cout << endl;

    myQueue.dequeue();
    myQueue.display();

    cout << "Queue full: " << myQueue.isFull() << endl;
    cout << "Queue empty: " << myQueue.isEmpty() << endl;

    return 0;
}