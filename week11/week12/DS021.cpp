#include <iostream>
using namespace std;

class Student{
    private:
        double getAvg() const;  //평균 계산 함수. 구현 필. 
    public:
        Student();  //생성자
        ~Student(); //소멸자
        string name;
        string sid;
        int* score;     //공간할당 필요.
        void print() const;     //결과 출력 함수. 구현 필
};

Student::Student(){
    score = new int[3];    //국 영 수 공간할당
}
Student::~Student(){
    delete[] score;    
}
double Student::getAvg() const{
    double avg = 0;
    avg = 1.0* (score[0]+ score[1]+ score[2]) / 3.0 ;
    return avg;
}
void Student::print() const{
    std::cout << "[" + sid + "] ";
    std::cout << name << endl;
    std::cout << "The Average score is ";

    std::cout.precision(1);
    std::cout << fixed << getAvg() << endl;
}

/* 국영수 이름 입력, 평균구하여 출력.
1. 이름 입력 by struct.
2. 평균 구하는 함수 만들기 - 구조체 포인터 보내어..
*/
int main(){
    Student student;    //새롭개 class 선언. 

    std::cout << "학번 국 영 수\n 이름 을 입력하세요...\n";
    std::cin >> student.sid;
    std::cin >> student.score[0];
    std::cin >> student.score[1];
    std::cin >> student.score[2];
    std::cin.ignore();
    getline(std::cin, student.name);

    student.print();
    return 0;
}
