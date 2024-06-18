//header 구현파일
#include <iostream>
#include "MyStack.h"
using namespace std;

MyStack::MyStack(int m){ 
/* ^위처럼 굳이 파라미터로 값을 받아올 떄 m처럼 받아오는 이유는 ? 
    > 필드에 const로 선언된 변수(상수)를 초기화하는 경우
    > 필드에 선언된 레퍼런스 변수를 초기화하는 경우    <- 좀따 push 에서 레버런스로 값을 받아올 때 쓰는듯,,??
*/
    //maxsize: (m) {}; 과 같다
    maxsize = m;
    top = -1;
    list = new string[maxsize];
}      

MyStack::~MyStack() {   //destructor
    delete[] list;
}          

void MyStack::initialize(){      
/*  스택 초기화
 1. List가 null이 되기 전까지 다음을 반복
 2. 처음부터 들어있는 모든 List의 값을 0으로 초기화. 
*/
    int i=0;
    while(list[i] == "" ){
        list[i] = "" ;
        i++;
    }
    top = -1;
}   

bool MyStack::isEmpty() const {    //비어있는 여부확인
/*
 stack이 비어있다 = top 에 아무것도 들어있지 않다. 
*/
    if( list[top] == "" ) return true;
    else return false;
}
bool MyStack::isFull() const {     //가득차있는 여부확인
/*
 stack이 꽉차있다 = maxsize-1 번째 index 가 존재한다. 
*/
    if(list[maxsize - 1] != "" ) 
        return true;
    else return false;
}

void MyStack::push(const string& e){  //reference type 값을 받아와서 stack에 넣는다.
/*
 top 부분에 새로운 값을 추가한다. 
 상수 타입의 element를 새로운 Index에 추가
 !exception : 가득 값이 차 있으면 stack overflow print.
*/
    if(isFull()){
        cout << "Stack Overflow!" << endl; 
        return ;
    }

    top++;
    list[top] = e;
}

string* MyStack::pop(){             //top의 값을 반환하고, stack에서 지운다.
    if(isEmpty()){
        cout << "Stack Underflow!" <<endl;
    }

    top--;
    return list;    //내용출력은 없음.
}

void MyStack::print(){           //현재 스택 값을 보여준다. 
    for(int i=0; i<=top; i++){
        cout << list[top-i] <<endl;
    }
}
