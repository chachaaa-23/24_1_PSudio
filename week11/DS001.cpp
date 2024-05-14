#include <iostream>
using namespace std;

//신장, 체중 입력
//비만여부 출력(yes/no)
int main() {
    int height, weight =0;
    double bmi=0.0;

    cout << "신장 입력";
    cin >> height;
    cout << "체중 입력";
    cin >> weight;
    bmi = weight / (height*0.01*height*0.01);

    if(bmi >=25 ){
        cout << "yes\n";
    }else cout << "No\n";

    return 0;
}