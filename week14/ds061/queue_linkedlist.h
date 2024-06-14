//https://www.codewhoop.com/queue/queue-using-linked-list.html
#include <iostream>
using namespace std;

// Structure of Node.
struct Node{
    int data;
    Node *link;
};

class Queue{
private:
    Node *front = nullptr;
    Node *rear = nullptr ;

public:
    bool isempty();
    void enqueue(int value);
    void dequeue();
    void showfront();
    void showrear();
    void displayQueue();

};


//Function to check if queue is empty or not
bool Queue::isempty(){
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

//function to enter elements in queue
void Queue::enqueue ( int value ){
    Node *ptr = new Node();
    ptr->data= value;
    ptr->link = NULL;

    //If inserting the first element/node
    if( front == NULL ){
        front = ptr;
        rear = ptr;
    }else{
        rear ->link = ptr;
        rear = ptr;
    }
}

//function to delete/remove element from queue
void Queue::dequeue(){
    if(isempty())
        cout<<"Queue is empty\n";
    else
    //only one element/node in queue.
        if( front == rear){
            free(front);
            front = rear = NULL;
        }

        else{
            Node *ptr = front;
            front = front->link;
            free(ptr);
        }   
}

//function to show the element at front
void Queue::showfront(){
    if( isempty())
        cout<<"Queue is empty\n";
    else
        cout<<"element at front : "<<front->data << endl;
}

void Queue::showrear(){
    if(isempty())
        cout<<"Queue is empty\n";
    else    
        cout<<"element at rear : "<< rear->data << endl;
}


//function to display queue
void Queue::displayQueue(){
    if (isempty())
        cout<<"Queue is empty\n";
    else{
        Node *ptr = front;
        while( ptr !=NULL){
            if(ptr != front)
                cout << " -> ";
            cout<<ptr->data;
            ptr= ptr->link;
        }
    }
}

