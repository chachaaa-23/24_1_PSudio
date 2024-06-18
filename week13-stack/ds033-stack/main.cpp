#include <iostream>
//cpp파일은 굳이 include안해도 header만 하면 알아서 된다. 
#include "CouponStack.h"
using namespace std;

/* 쿠폰을 관리하는 스택. 원하는 순서대로 쿠폰을 넣고 꺼내기!
각각의 명령문을 입력 대기로 받는다.
 1.push
 - if push 가 입력으로 들어오면, 뒤에 들어오는 숫자를 받아서
 - 이를 넣는다.
*/
int main(){
    string input;
    int inputMaxsize;

    cin >> inputMaxsize;
    CouponStack couponstack(inputMaxsize);  //스택크기 설정하고 새로만들기. java의 인스턴스화 생각하기!
//cout << "***debug    새로운 객체 생성. maxsize =  " << inputMaxsize << endl;

    while(1){
        cin >> input;
//cout << "***debug    input입력 -> " << input << endl;

        if( input == "+" ){
            coupon newc;
            cin >> newc.rank;
            //버퍼 ㄱㅊ?
            cin >> newc.prizeName;

//cout << "***debug    push 실행 " << endl;

            couponstack.push(newc);
        }
        else if( input == "-" ){
            couponstack.pop();
//cout << "***debug    pop 실행 " << endl;

        }
        else if( input == "q" ) break;
    }

    return 0;
}