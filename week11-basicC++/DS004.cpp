#include <iostream>
using namespace std;
/*
국영수 점수 입력받아
총점과 평균, pass여부(70점 이상) 출력하기
*/
struct st_score
    {
        int kor, eng, math;
        int total;
        double average;
    };

int main(){
    struct st_score score;
    cin >> score.kor >> score.eng >> score.math;

    score.total = score.kor + score.eng + score.math ;    
    score.average = score.total / 3.0 ;

    cout.precision(1);
    cout <<fixed << score.total << " " << score.average << endl;

    cout << "Korean - " ;
    if(score.kor >= 70)
        cout << "Pass" << endl;
    else cout << "Fail" << endl;

    cout << "English - " ;
    if(score.eng >= 70)
        cout << "Pass" << endl;
    else cout << "Fail" << endl;

    cout << "Math - " ;
    if(score.math >= 70)
        cout << "Pass" << endl;
    else cout << "Fail" << endl;

    return 0;
}