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
    int operandsNum = 0;
    int operaterNum = 0;

    while(1){
        cin >> input;
//cout << "***debug    input입력 -> " << input << endl;

        if( input == "#" ){ //정수 들어오면 stack에 Push
        operandsNum++;
            int num = 0;
            cin >> num;

//연산자에 비해서 숫자가 많은 경우, 오류출력. 
            if(operandsNum <= operaterNum+1){
                cout << "\nToo many operands !!!";
                mystack->initialize();
                continue;
            }
            mystack->push(num);
        }
        else if( input == "*" ){    //곱하기 표시. 두개를 pop해서 곱하고, 이를 다시 push..
            operaterNum++;
            int num1, num2, num3 = 0;
            num1 = mystack->pop();
            num2 = mystack->pop();

            num3 = num2* num1;
            mystack->push(num3);
        }
        else if( input == "/" ){
            operaterNum++;
            int num1, num2, num3 = 0;
            num2 = mystack->pop();
            num1 = mystack->pop();

            if(num1 == 0 || num2 == 0){
                cout << "\n=> Division by 0 !!!" << endl;
                mystack->initialize();  //안에 든 기존의 모든 연산 제거. 
                continue;
            }
            num3 = num1 / num2;
            mystack->push(num3);
//cout << "***debug    pop 실행 " << endl;
        }
        else if( input == "+" ){
            operaterNum++;
            int num1, num2, num3 = 0;
            num2 = mystack->pop();
            num1 = mystack->pop();

            num3 = num1 + num2;
            mystack->push(num3);
//cout << "***debug    top 실행 " << endl;
        }else if( input == "-"){
            operaterNum++;
            int num1, num2, num3 = 0;
            num2 = mystack->pop();
            num1 = mystack->pop();

            num3 = num1 - num2;
            mystack->push(num3);
//cout << "***debug    print 실행 " << endl;
        }else if( input == "="){
            int num1;
            cout << mystack->pop() <<endl;  
//cout << "***debug    clear 실행 " << endl;
        }else if( input == "q"){
            mystack->~MyLinkedStack();
//cout << "***debug    q 실행 " << endl;
            break;
        }
        else{
        cout << "\n=> Expression error !!!" <<endl;
        }
    }

    return 0;
}