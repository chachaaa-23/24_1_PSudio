#include <iostream>
#include "queue_linkedlist.h"
using namespace std;

/* 바꿀 조건
1. Linkedlist 버전 큐 만들기
2. showrear 함수를 위한 새로운 queue의 멤버 함수 Rear 제작
 3. Queue 라이브러리화
4. 실행 예시와 같은 값 나오게 코드수정
*/

//Main Function
int main(){
    int choice, flag=1, value;
    Queue queue;
    while( flag == 1){
        cout<<"\n1.enqueue 2.dequeue 3.showfront 4.showrear 5. displayQueue 6.exit > ";
        cin>>choice;
        switch (choice){
            case 1: cout << "Enter a Value: ";
                    cin>>value;
                    queue.enqueue(value);
                    break;
            case 2: queue.dequeue();
                    break;
            case 3: queue.showfront();
                    break;
            case 4: queue.showrear();
                    break;
            case 5: queue.displayQueue();
                    break;
            case 6: flag = 0;
            cout << "bye!" << endl;
                    break;
        }
    }

 return 0;
}