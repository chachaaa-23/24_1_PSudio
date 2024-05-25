#include <iostream>
using namespace std;
#define MAX 50

/* 쇼핑몰 상품 정보 관리
1. 클래스 생성 - 상품 한 개의 정보를 다루는 클래스
2. CRUD 프로그램 형식 (Add, List, Quit)
버펴오류 주의 (int -> string입력 시 문제발생.)
*/

class Product{
    private: 
        string name;
        int price;
        int saleRate;
        string madeBy;
        int gram;
    public:
        Product productInput();
        void productPrint(Product p);
        int calculatePrice(Product p);
};
Product Product::productInput(){
    /* 상품 입력
    - 상품명(공백 유), 가격, 할인율, 용량, 제조사(공백x)
    하나 class 만들고, 거기에 값들을 입력받는다. 
    */
   Product p;
   cin.ignore();

    cout << "상품명" <<endl;
    getline(cin, p.name);

   cout << "가격" <<endl;
   cin >> p.price;

   cout << "할인율" <<endl;
   cin >> p.saleRate;

   cout << "용량" << endl;
   cin >> p.gram;
   cin.ignore();    //q버퍼비움

   cout << "제조사" <<endl;
   cin >> p.madeBy;

    return p;
}
int Product::calculatePrice(Product p){
    //할인된 가격으로 출력하기.
    float saledPrice = 0.0;
    saledPrice = (p.price - ( p.price * ( 1.0* p.saleRate / 100.0)) ) ;
    return (int)saledPrice;
}

void Product::productPrint(Product p){
    //입력된 내용들을 출력한다. 
    int saledPrice = p.calculatePrice(p);
    cout << saledPrice << " ";
    cout << "(-" << p.saleRate << "%) ";
    cout << p.name << " ";
    cout << p.gram << " ";
    cout << p.madeBy <<endl;
}

int main(){
    Product *p = new Product[MAX];
    int input=0;
    int count=0;

    while(1){
        cout << "1. Add 2.List 3. Quit > ";
        cin >> input;

        switch(input){
            case 1 :
                p[count] = p[count].productInput();
                count++;
                break;

            case 2: 
                for(int i=0; i<count; i++)
                    p[i].productPrint(p[i]);
                    break;
            
            case 3:
                delete[] p;
                return 0;

            default:
                cout << "잘못된 입력..." << endl;
                break;
        }
    }

}