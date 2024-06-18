#include <iostream>
#include "queue_linkedlist.h"
using namespace std;

/* queue활용한 카드게임 만들기
queue 활용 = 각 플레이어의 카드 덱에 수를 차례대로 enqueue.

1. 카드 개수 입력받기 - queue의 크기 결정, 몇개의 덱을 입력받을 것인지..
2. 각 플레이어의 큐에서 카드를 꺼내어 비교한다

 비교하는 게 첫번재라면 그냥 대소 비교,
 general case: 
  이전 라운드 승자 찾기
  승자 카드패: 현재 카드숫자 큐 + (이전라운드 자신의 대결숫자- 이전라운드 상대의 대결숫자 -1)
  패자 카드패: 그냥 현재 카드숫자.
  
 각 라운드별 어떤 플레이어의 승패여부를 변수에 저장한다. 
 이전라운드 숫자 변수에 각자 현재 수 넣기
 카드게임을 카드 개수만큼 반복한다.

3. 최종 결과를 계산
4. 결과 출력

*/

int main(){
     Queue myqueue1;
     Queue myqueue2;
     
//변수 설정
     int input;
     int deck = 0;
     cin >> deck;
     int player_WinOrLose[deck] ;      //승패여부, p1 win=1, p2 win=2, 무승부=0 저장.
     int currentdeck[2] = {0};
     int lastdeck[2] = {0};

//수 입력
     for(int i=0; i<deck*2; i++){
        cin >> input;
        if(i < deck) myqueue1.enqueue(input);
        else myqueue2.enqueue(input);
     }

//덱 비교
     for(int i=0; i<deck; i++){

        currentdeck[0] = myqueue1.dequeue();   
        currentdeck[1] = myqueue2.dequeue();   

        if(i!=0) {
             if(player_WinOrLose[i-1] == 1){   //전라운드에 p1 이긴 경우
                     currentdeck[0] = currentdeck[0] + (lastdeck[0] - lastdeck[1] - 1);
              }else if(player_WinOrLose[i-1] == 2) {
                     currentdeck[1] = currentdeck[1] + (lastdeck[1] - lastdeck[0] - 1);
              }
        }
        //값 비교
        if (currentdeck[0] > currentdeck[1]){
                player_WinOrLose[i] = 1;
        } else if (currentdeck[0] < currentdeck[1]){
                player_WinOrLose[i] = 2;    
        } else player_WinOrLose[i] = 0;

        for(int i=0; i<2; i++)
              lastdeck[i] = currentdeck[i];
     } 

//최종 승자
        int p1, p2, winner = 0;
        for(int i=0; i<deck; i++){
                if(player_WinOrLose[i] == 1) p1++;
                else if(player_WinOrLose[i] == 2) p2++;
        }
        if(p1 > p2) winner = 1; //p1 이 승자
        else if(p1 < p2) winner = 2;
        else winner = 0;        //동점

//결과출력
        for(int i=0; i<deck; i++){
                cout << "Round" << i+1<< " - ";
                if(player_WinOrLose[i] == 1) cout << "P1 win!"<<endl;
                else if(player_WinOrLose[i] == 2) cout << "P2 win!"<<endl;
                else cout << "Draw!" <<endl;
        }
        cout << "Final - ";
        if(winner == 1) cout << "P1 win!"<<endl;
        else if(winner == 2) cout << "P2 win!"<<endl;
        else cout << "Draw!"<<endl;

     return 0;
}

