//header 구현파일
#include <iostream>
#include "CouponStack.h"
using namespace std;

CouponStack::CouponStack(int m){ 
/* ^위처럼 굳이 파라미터로 값을 받아올 떄 m처럼 받아오는 이유는 ? 
    > 필드에 const로 선언된 변수(상수)를 초기화하는 경우
    > 필드에 선언된 레퍼런스 변수를 초기화하는 경우    <- 좀따 push 에서 레버런스로 값을 받아올 때 쓰는듯,,??
*/
    //maxsize: (m) {}; 과 같다
    maxsize = m;
    top = -1;
    list = new coupon[maxsize];
}      

CouponStack::~CouponStack() {   //destructor
    delete[] list;
}          

void CouponStack::initialize(){      
/*  스택 초기화
 1. List가 null이 되기 전까지 다음을 반복
 2. 처음부터 들어있는 모든 List의 값을 0으로 초기화. 
*/
    int i=0;
    
    //(구조체 초기화)구조체에서 어떻게 비어있다고 판정내릴 수 있을까? -> 그냥 구조체 중 한가지 element 값 통해 판별하기.
    while(list[i].prizeName == "" ){
        list[i].rank = 0 ;
        list[i].prizeName = "" ;
        i++;
    }
    top = -1;
}   

bool CouponStack::isEmpty() const {    //비어있는 여부확인
/*
 stack이 비어있다 = top 에 아무것도 들어있지 않다. 
*/
    if( list[top].prizeName == "" ) return true;
    else return false;
}
bool CouponStack::isFull() const {     //가득차있는 여부확인
/*
 stack이 꽉차있다 = maxsize-1 번째 index 가 존재한다. 
*/
    if(list[maxsize - 1].prizeName != "" ) 
        return true;
    else return false;
}

void CouponStack::push(const coupon& e){  //reference type 값을 받아와서 stack에 넣는다.
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

coupon* CouponStack::pop(){             //top의 값을 반환하고, stack에서 지운다.
    if(isEmpty()){
        cout << "Stack Underflow!" <<endl;
    }
    print();
    top--;
    return list;    //내용출력까지 하기.
}

void CouponStack::print(){           //현재 스택 값을 보여준다. 
    if(isEmpty()) return ;
    cout << list[top].rank  << "등 - " << list[top].prizeName <<endl;
}
