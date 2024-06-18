//int type 숫자관리 스택 테스트
#include <iostream>
//#include "MyStack.cpp"
#include "MyStack.h"
using namespace std;

/*
각각의 명령문을 입력 대기로 받는다.
 1.push
 - if push 가 입력으로 들어오면, 뒤에 들어오는 숫자를 받아서
 - 이를 넣는다.
*/
int main(){
//cout << "***debug   프로그램 실행중!" << endl;
    string input;
    int inputMaxsize;
    cin >> inputMaxsize;

    MyStack mystack(inputMaxsize);  //스택크기 설정하고 새로만들기. java의 인스턴스화 생각하기!
//cout << "***debug   스택 만들기 성공!" << endl;

    while(1){
        cin >> input;
//cout << "***debug    다음의 입력값 받음 : " << input << endl;


        if( input == "push" ){
            int newElement ;
            cin >> newElement;

            mystack.push(newElement);
//cout << "***debug   push 실행, 입력값 : " << newElement << endl;

        }
        else if( input == "pop" ){
            mystack.pop();
//cout << "***debug    pop 실행" << endl;

        }
        else if( input == "print" ){
//cout << "***debug    Print 실행" << endl;

            mystack.print();
            break;
        }
    }

    return 0;
}