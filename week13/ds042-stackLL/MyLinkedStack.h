#include <iostream>
using namespace std;
//linked list를 이용한 Stack 만들기. 

class Node {
    private:
        int data;       //바깥의 class에서 접근 불가, getter/setter 필요
        Node* next;     

    public:
        Node(int data);     //constructor
        int getData();
        void setData(int d);
        Node* getNext();
        void setNext(Node* n);

};
Node::Node(int data){
    this->data = data;  //밖의 원본 변수를 가리키기 위해 this사용. 포인터이므로 -> 연산자 사용
    next = nullptr;
}
int Node::getData(){
    return data;
}
void Node::setData(int d){
    data = d;
}
Node* Node::getNext(){
    return next;
}
void Node::setNext(Node* n){
    next = n;
}

class MyLinkedStack {
    private:
        Node* stacktop;

    public:
        void initialize();
        bool isEmpty() const;
        void push(const int& d);
        int pop();
        int top() const;
        int getNodeCnt() const ;    //node의 개수를 가져옴
        MyLinkedStack();
        ~MyLinkedStack();
        void printAll();    //stack을 pop 순서로 출력 (pop은 안함)
};
MyLinkedStack::MyLinkedStack(){stacktop = nullptr;}
MyLinkedStack::~MyLinkedStack(){
    while(!isEmpty())   
        pop();
}

void MyLinkedStack::initialize(){       //초기화
    stacktop = nullptr;
}

bool MyLinkedStack::isEmpty() const{
    return stacktop == nullptr;
}
void MyLinkedStack::push(const int& d){
    Node* newNode = new Node(d);    //new를 통해 NOde 객체 생성..
    if(isEmpty()){
        stacktop = newNode;
        return ;
    }
    newNode->setNext(stacktop);
    stacktop = newNode;
}

int MyLinkedStack::pop(){
    /*
    head에서 연결을 끊고 
    Head의 위치를 옮긴다
    HEad를 Free 시킨다.
    */
    if(isEmpty()){
        //cout << "Empty Stack!" <<endl;
        return 0;
    }
    Node* cur = stacktop;   // 위치값 설정. 
    Node* next = cur->getNext();    //다음 top..
    int num = cur->getData();

    stacktop = next;
    cur->setNext(nullptr);
    delete cur;
    return num;
}

int MyLinkedStack::top() const{
    if(isEmpty()){
        //cout << "Empty Stack!" << endl;
        return 0;
    }
    return stacktop->getData();
}
int MyLinkedStack::getNodeCnt() const {
//top부터 끝의 Node(node->next == nullptr)까지 반복문. 
    int count =0; 
    Node* cur = stacktop;
    while(cur != nullptr){
        count++;
        cur = cur->getNext();
    }    
    return count;
}    //node의 개수를 가져옴
void MyLinkedStack::printAll(){     //stack을 pop 순서로 출력 (pop은 안함)
    Node* search = stacktop;
    while(search != nullptr){
        cout << search->getData() << endl ;
        search = search->getNext();
    }
}