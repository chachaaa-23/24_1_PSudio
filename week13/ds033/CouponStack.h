#include <iostream>
using namespace std;
//class header. only definition here

struct coupon{
    int  rank;  
    string prizeName;
} ;

class CouponStack{
    private:
        int maxsize;
        int top;
        coupon* list; 

    public:
        CouponStack(int m);      //최고사이즈 설정해주는 생성자
        ~CouponStack();             //destructor
        void initialize();      //스택 초기화
        bool isEmpty() const;   //비어있는 여부확인
        bool isFull() const;    //가득차있는 여부확인
        void push(const coupon& e);  //reference type 값을 받아와서 stack에 넣는다.
        coupon* pop();             //top의 값을 반환하고, stack에서 지운다.
        void print();           //현재 값을 보여준다. 
};