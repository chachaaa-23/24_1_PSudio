#include <iostream>
#include <string>
#include "MyLinkedStack.h"
using namespace std;

/* 
일반 입력 = 왼쪽 stack 에 저장 
< 왼쪽 스택에 저장, 
> 오른쪽 스택에 저장
일반입력, 그냥 출력..(아마 왼쪽스택에 넣고, 출력의 역순으로 놓지 않을까..?)
*/
int main(){
    string input;

    MyLinkedStack* mystack = new MyLinkedStack();  //스택 새로만들기. 

    while(1){
        cin >> input;

        if( input[0] == '#' ){ //정수 들어오면 stack에 Push

        }else if( input == "q"){
            mystack->~MyLinkedStack();

            break;
        }
        
    }

}