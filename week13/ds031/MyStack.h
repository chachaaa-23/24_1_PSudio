#include <iostream>
using namespace std;
//class header. only definition here

class MyStack{
    private:
        int maxsize;    //스택 최대사이즈
        int top;        //가장 최근에 들어온 element의 Index번호
        int *list;      //int type의 숫자들을 보관하는 array의 첫번째값. 
        //^ 동적할당을 통해 maxsize만큼의 공간을 만들어줘야 한다. 

    public:
        MyStack(int m);      //최고사이즈가 10이 되도록 설정해주는 생성자
        ~MyStack();             //destructor
        void initialize();      //스택 초기화
        bool isEmpty() const;   //비어있는 여부확인
        bool isFull() const;    //가득차있는 여부확인
        void push(const int& e);  //reference type 값을 받아와서 stack에 넣는다.
        int* pop();             //top의 값을 반환하고, stack에서 지운다.
        void print();           //현재 값을 보여준다. 
};