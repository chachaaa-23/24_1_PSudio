#include <iostream>
using namespace std;

/*
날짜를 월과 일로 받아, 일년 중 몇번째 날인지 계산.
switch문 사용해서 n월 -> 30/31/28일 더해지고
일수 더하기
결과출력
*/
int main() {
    int month, day=0;
    int day_count=0;

    cin >> month >> day;
    switch(month) {
    case 12: 
        day_count += 31;
    case 11: 
        day_count += 30;
    case 10: 
        day_count += 31;
    case 9: 
        day_count += 30;
    case 8: 
        day_count += 31;
    case 7: 
        day_count += 31;
    case 6: 
        day_count += 30;
    case 5: 
        day_count += 31;
    case 4: 
        day_count += 30;
    case 3: 
        day_count += 31;
    case 2: 
        day_count += 28;
    case 1: 
        break;  
    }

    day_count += day;
    cout << day_count << endl;  //end line.

    return 0;
}