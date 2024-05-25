#include <iostream>
using namespace std;

class EngForGradu{
    private: 
        string name;
        int LCScore;
        int RCScore;

    public: 
        EngForGradu(){      //생성자, 입력도 받음.
            getline(cin,name);
            //cin.ignore();

            while(1){
                cout << "LC> ";
                cin >> LCScore;
                if(isValidScore(LCScore))   
                    break;
            }
            while(1){
                cout << "RC> ";
                cin >> RCScore;     
                if(isValidScore(RCScore))   
                    break;
            }
            
        }      
        EngForGradu(string n, int LSscore, int RCscore);    
        //^멤버변수 parameter가 있는 생성자
        //점수 유효성 체크함수. 
        bool isValidScore(int score);
        //출력메소드
        void print();
        //pf메소드
        string isPass(int score);
};
bool EngForGradu::isValidScore(int score){
    if(score <= 495 && score >= 0 )
        return true;
    else return false;
}

void EngForGradu::print(){
    cout << "["+ name + "]"<< endl;
    cout << "LC - " << LCScore << " " ;
    cout<< isPass(LCScore)<< endl;

    cout << "RC - " << RCScore << " ";
    cout<< isPass(RCScore) << endl;
    cout << "Total - " << (LCScore + RCScore) << endl ;

}

string EngForGradu::isPass(int score){
    if(score >=350 && score <=495)
        return "Pass";
    else return "Fail";
}

/* 졸업영어성적 판단
학생 이름, LC, RC 점수 입력받기.
- 0~495 사이의 점수만 입력받기, 아니면 다시 입력..
총점 출력, 각각 350이상이면 P, 아니면 F.

*/
int main(){
    EngForGradu forGraduation;  //instiation with initialize.
    forGraduation.print();
    
    return 0;
}