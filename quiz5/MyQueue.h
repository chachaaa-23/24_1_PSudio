#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class MyQueue {
private:
    T* list;
    int maxsize;
    int front;
    int rear;

public:
    MyQueue(int n);         // Constructor
    ~MyQueue();            // Destructor
    void initialize();     // Initialize the queue
    bool isEmpty() const;  // Check if the queue is empty
    bool isFull() const;   // Check if the queue is full
    void enqueue(const T& elem); // Add element to the queue
    void dequeue();        // Remove element from the queue
    T Front() const;       // Get the front element
    T Rear() const;        // Get the rear element
    void print() const;    // Print the queue
    int size() const;      // Get the number of elements in the queue
    void printDetail() const; // Print details of the queue
    void queueActivePrint(int& enq, int& deq); // Print enqueue and dequeue activities
};

template <typename T>
MyQueue<T>::MyQueue(int n) {
    maxsize = n;
    list = new T[maxsize];
    front = -1;
    rear = -1;
}

template <typename T>
MyQueue<T>::~MyQueue() {
    delete[] list;
}

template <typename T>
void MyQueue<T>::initialize() {
    for (int i = 0; i < rear; i++) {
        list[i] = T();
    }
    front = -1;
    rear = -1;
}

template <typename T>
bool MyQueue<T>::isEmpty() const {
    return (front == -1);
}

template <typename T>
bool MyQueue<T>::isFull() const {
    return (rear - front + 1 == maxsize); //현재길이 = 최대사이즈? 
}

template <typename T>
void MyQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % maxsize;
    }
    list[rear] = elem;
}

template <typename T>
void MyQueue<T>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    front = (front + 1) % maxsize;
    if (front == (rear + 1) % maxsize) {
        front = rear = -1;
    }
}

template <typename T>
T MyQueue<T>::Front() const {
    if (isEmpty()) {
        return T();
    }
    return list[front];
}

template <typename T>
T MyQueue<T>::Rear() const {
    if (isEmpty()) {
        return T();
    }
    return list[rear];
}

template <typename T>
void MyQueue<T>::print() const {
    if (isEmpty()) {
        cout << endl;
        return;
    }
    for (int i = 0; i < size(); i++) {
        cout << "[" << list[(front + i) % maxsize] << "]";
    }
    cout << endl;
}

template <typename T>
int MyQueue<T>::size() const {
    if (isEmpty()) return 0;
    return (rear - front + maxsize) % maxsize + 1;
}

template <typename T>
void MyQueue<T>::printDetail() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Size: " << size() << endl;
    cout << "Queue: ";
    print();
    cout << "Index: ";
    for (int i = 0; i < size(); i++) {
        cout << (front + i) % maxsize << " ";
    }
    cout << endl;
    cout << "Front: " << front << ", Rear: " << rear << endl;
}

template <typename T>
void MyQueue<T>::queueActivePrint(int& enq, int& deq) {
    if (deq > 0) {
        cout << "===== Dequeue x " << deq << " =====" << endl;
        if (isEmpty()) {
            cout << "=> Queue is empty!" << endl;
        }
    }
    if (enq > 0) {
        cout << "===== Enqueue x " << enq << " (";
        if (enq == 1) {
            cout << list[rear] << ")";
        } else {
            cout << list[(rear - enq + 1 + maxsize) % maxsize] << " ~ " << list[rear] << ")";
        }
        cout << " =====" << endl;
        if(isFull())
            cout << "=> Queue is full!" <<endl;
    }
    enq = 0;
    deq = 0;
}

#endif
