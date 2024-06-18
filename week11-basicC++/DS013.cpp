#include <iostream>
using namespace std;
/*  카페메뉴 관리

*/
struct Menu{
    string menuName;
    int price;
};
struct Cafe{
    string name;
    int menuNum;
    Menu* menu;
};

void addCafe(Cafe &r1);
void addMenu(Menu &m1);
void displayMenus(Cafe &r1);

int main(){
    Cafe cafe;
    addCafe(cafe);  //이름, 메뉴개수 입력
    displayMenus(cafe);

    return 0;
}

void addCafe(Cafe &r1){
    //이름, 메뉴개수 입력
    getline(cin, r1.name);
    cin >> r1.menuNum;

    r1.menu = new Menu[r1.menuNum];
    for(int i=0; i<r1.menuNum; i++)
        addMenu(r1.menu[i]);
}

void addMenu(Menu &m1){
    //메뉴입력
        cin >> m1.menuName;
        cin >> m1.price;
}

void displayMenus(Cafe &r1){
    cout << "===== " + r1.name + " =====\n";
    for(int i=0; i<r1.menuNum; i++){
        cout << r1.menu[i].menuName + " " << r1.menu[i].price << endl;
    }
    cout << "------------------\n";
}