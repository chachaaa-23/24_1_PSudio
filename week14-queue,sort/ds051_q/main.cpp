#include "MyQueue.h"
#include <iostream>

int main() {
    MyQueue<int> myqueue(10);
    int enqtimes = 0;
    int deqtimes = 0;

    myqueue.dequeue();
    deqtimes++;
    myqueue.queueActivePrint(enqtimes, deqtimes);
    myqueue.printDetail();

    int input1[] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < sizeof(input1) / sizeof(input1[0]); i++) {
        myqueue.enqueue(input1[i]);
        enqtimes++;
    }
    myqueue.queueActivePrint(enqtimes, deqtimes);
    myqueue.printDetail();

    for (int i = 0; i < 3; i++) {
        myqueue.dequeue();
        deqtimes++;
    }
    myqueue.queueActivePrint(enqtimes, deqtimes);
    myqueue.printDetail();

    int input2[] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < sizeof(input2) / sizeof(input2[0]); i++) {
        myqueue.enqueue(input2[i]);
        enqtimes++;
    }
    myqueue.queueActivePrint(enqtimes, deqtimes);
    myqueue.printDetail();

    return 0;
}