#include "MyQueue.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    MyQueue<int> myqueue(10);   //큐 선언
    string input ="";
//    string en = "en";
    while(1){
        cin >> input;
        if (input.find("en") != string::npos) {    // 'en' 입력시            //집어넣을 정수 입력받고
            int input=0;
            cin >> input;       //버퍼 ㄱㅊ..?
            //queue에 넣기
            myqueue.enqueue(input);
            continue;
        }
        if(input == "de"){
           myqueue.dequeue();
            continue;
        }            
        if(input == "front"){
            cout << "=> " << myqueue.Front() << endl;
            continue;
        }
        if(input == "rear"){
            cout << "=> " << myqueue.Rear() << endl;
            continue;
        }
        if(input == "size"){
            cout << "=> " << myqueue.size() << endl;
            continue;
        }
        if(input == "empty"){
            if(myqueue.isEmpty())
                cout << "=> 1" <<endl;
            else cout << "=> 0" <<endl;
            continue;
        }
        if(input == "print"){
            myqueue.print();
            continue;
        }
        if(input == "q"){
            cout << "bye!" <<endl;
            break;
        }
    }

   
    return 0;
}