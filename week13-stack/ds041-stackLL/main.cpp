#include <iostream>
//cpp파일은 굳이 include안해도 header만 하면 알아서 된다. 
#include "MyLinkedStack.h"
using namespace std;

/* linked list를 통한 스택 만들기. 숫자를 관리한다
*/
int main(){
    string input;

    MyLinkedStack* mystack = new MyLinkedStack();  //스택 새로만들기. java의 인스턴스화 생각하기!
//cout << "***debug    새로운 객체 생성. maxsize =  " << inputMaxsize << endl;

    while(1){
        cin >> input;
//cout << "***debug    input입력 -> " << input << endl;

        if( input == "push" ){
            int topush;
            cin >> topush;
            mystack->push(topush);
//cout << "***debug    push 실행 " << endl;
        }
        else if( input == "pop" ){
            mystack->pop();
//cout << "***debug    pop 실행 " << endl;
        }
        else if( input == "top" ){
            cout << "top : " << mystack->top() << endl;
//cout << "***debug    top 실행 " << endl;
        }else if( input == "print"){
            mystack->printAll();
//cout << "***debug    print 실행 " << endl;
        }else if( input == "clear"){
            mystack->initialize();
//cout << "***debug    clear 실행 " << endl;
        }else if( input == "q"){
            mystack->~MyLinkedStack();
//cout << "***debug    q 실행 " << endl;
            break;
        }
    }

    return 0;
}