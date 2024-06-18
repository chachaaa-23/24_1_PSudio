#include <iostream>
using namespace std;
/*  구조체 비교문제
 두개의 구조체 정의
 각 구조체 내용 입력
 각 구조체의 상품이름&가격 일치시 같은 것임 나타냄
 그렇지않으면 not equal..

*/
struct product{         //구조체 초기화
    string name;
    int value;
    string manufact;
};
bool calculate(product* p);

int main(){
    product* p = new product[2];   //동적 메모리 할당 by new. 
    
    cin >> p[0].name ;      //각 element 입력
    cin >> p[0].value ;
    cin >> p[0].manufact ;

    cin >> p[1].name ;
    cin >> p[1].value ;
    cin >> p[1].manufact ;
//함수로 포인터변수 넘겨줘서 같은지 다른지 여부 받아온다. 
    bool isSame = calculate(p);

    cout << p[0].name + " and " + p[1].name;
    if(isSame == true){
        cout << " is equal\n";
    }else
        cout << " is not equal.\n";
    return 0;
}

//두 구조체가 같은지 확인. 결과 출력.
bool calculate(product* p){
    bool sameCheck = true;
    if(p[0].name != p[1].name){
        sameCheck = false;
    }
    if(p[0].value != p[1].value){
        sameCheck = false;
    }

    if(sameCheck == true)
        return true;
    else {
        return false;
    }

}