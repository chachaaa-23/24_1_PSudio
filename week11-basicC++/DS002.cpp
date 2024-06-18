#include <iostream>
#include <cmath>
using namespace std;

//좌표 두개 입력받고
//두 좌표간의 거리 계산
int main() {
    double x1, y1 = 0.0;
    double x2, y2 = 0.0;
    double dist = 0.0;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    dist = sqrt (pow((x2 - x1), 2) + pow( (y2 - y1), 2) );
    //x^y <- pow(x, y)
    cout.precision(1); // 출력 정밀도 설정 (소숫점 아래 몇자리까지?)
    cout << fixed << dist << endl; // 소수점 이하 2자리까지 출력 (fixed 무조건 붙여야함)

    return 0;
}