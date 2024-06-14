#include <iostream>
#include "queue_linkedlist.h"
using namespace std;

/* linked list queue사용한 피보나치 수열
피보나치 수열 
 현재 수 = n-1번째의 수 + n-2번째의 수
 이 계산을 입력한 수 만큼 반복한다. 
 n=1, 2 일때는 예외적으로 결과가 1 

Queue로 나타내는법?
계산이 완료된 것을 차례대로 enque한다. 
*/

int main(){
     Queue myqueue;
     int number, i = 0;
     cin >> number;

     while(number > i){
        if(i == 0 ){
                myqueue.enqueue(1);
                i++;
                cout << "1st : 1" <<endl;
                continue;
        }
        if(i == 1){
                myqueue.enqueue(1);
                i++;
                cout << "2nd : 1" <<endl;
                continue;
        }
        int privNum = myqueue.dequeue();
        int morePrivNum = myqueue.dequeue();
        int newnum = privNum + morePrivNum;

        if(i == 2) cout << "3rd : 2" << endl;
        else cout << i+1 << "th : " << newnum <<endl;
        myqueue.enqueue(newnum);
        myqueue.enqueue(privNum);
        i++;
     }
     cout << "=> fibonacci(" << number << ") : " << myqueue.dequeue() <<endl;
}

