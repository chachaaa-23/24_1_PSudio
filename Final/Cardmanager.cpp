#include "cardManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

extern map<string, Card*> allclasses;

CardManager::~CardManager(){
    vector<Card*>::iterator iter;
    for (iter = myclasses.begin(); iter != myclasses.end(); ++iter) {
		delete (*iter); //각각의 card vector, 일일히 deallocate
	}
}

//클래스 총 개수, 학점, GPA 계산결과 출력
void CardManager::printAll(){   //#1
    int total_credit = 0;
    double gpa = 0.0;
    int count =0;
    for (int i=0; i<myclasses.size(); i++){
        std::cout << i+1 << " | " << myclasses[i]->toString() << endl;

        total_credit += myclasses[i]->getCredit();
        gpa += myclasses[i]->getScore() * myclasses[i]->getCredit();
        count ++;
    }
    //cout << "gpa " <<gpa <<endl;
    //cout << "total_credit" << total_credit << endl;
    gpa = gpa / (total_credit * 1.0) ;

    std::cout << "Total " << count << " classes, " << total_credit << " credit, GPA " ;
    std::cout.precision(2);
    std::cout << fixed << gpa <<endl;
}

//중복추가 막는 기능
//등급 입력 시 정해진 것들만 입력하게 - gradeScore 키값 참고
void CardManager::addCard(){    //#2
    string code, grade;
	std::cout << ">> Enter class code > ";
	cin >> code;
    cin.ignore();

//    int count = this->count;
//cout << "count " << count ;
    if(allclasses.count(code) > 0 ){     //입력받은 키값에 해당하는 원소 존재 + && myclass에 이미 들어가있는지도!

        for(int i=0; i<count; i++){
    //cout << "check1\n";
    //cout << "myclasses[i]->getCode() : " << myclasses[i]->getCode() <<endl;
    //cout << "code : " << code <<endl;

            if( myclasses[i]->getCode() == code ){
                cout << "Card of " << code << " is already exist." <<endl ;
                return;
            }
        }        

    //cout << "check2\n";
        cout << allclasses[code]->toStringShort() << endl;

	    cout << ">> Enter grade > ";
	    cin >> grade;
        cin.ignore();

        if(!(grade == "A+" || grade == "A0" || grade == "B+" || grade == "B0" || grade == "C+" || grade == "C0" || grade == "D+" || grade == "D0" || grade == "F" )){
            cout << "유효하지 않은 등급 입력!" <<endl;
            return;
        }

        Card* new_card = new Card(allclasses[code], grade);
        //새로운 card객체 만들어서 Vector에 넣기(스택같은 것)
        myclasses.push_back(new_card);
        count++;
        total_credit += new_card->getCredit();
    }
    else{
        cout << "No such class." << endl;
    }
}


//입력받은 카드번호 유효?
//변경학점 입력 후 진짜 수정할건지 확인사살하기
void CardManager::editCard(){   //#3
	int no;
    string new_grade;
	cout << ">> Enter a Card number > ";
	cin >> no;

    int i=0;
    if( no < 1 && no > count ){
            cout << "유효하지 않은 카드번호!" <<endl ;
            return;
        }
    cout << myclasses[no-1]->toString() << endl;

    cout << ">> Enter new grade > ";
    cin >> new_grade;

    int change = 0;     //1 = yes, 2= no
    cout << ">> Do you want to cange the grade of Card " << myclasses[no-1]->getCode() << "?     1 = yes, 2= no " <<endl;
    cin >> change;
    if(change == 2)
        return ;

    myclasses[no-1]->setGrade(new_grade);
    cout << "Grade changed." << endl;	
}

void CardManager::sortByCode(){     //#4
    sort(myclasses.begin(), myclasses.end(), Card::cmpCode);
}

void CardManager::loadCards(string filename){   //#6
    string line, code, grade;
    count=0;
	ifstream file(filename);
	while(!file.eof()){
        if(file.eof()) break;

		file >> code >> grade;
        Card* new_card = new Card(allclasses[code], grade);
        myclasses.push_back(new_card);
        count++;
        total_credit += new_card->getCredit();
	}
	file.close();
    cout << count << " classes are loaded.\n";
}

void CardManager::findCards(string name){   //#5
	int found = 0;
	cout << "Searching keyword: " << name << endl;
    for (int i=0; i<myclasses.size(); i++){
		if(myclasses[i]->getName().find(name) != string::npos){
			found++;
            cout << i+1 << " | " << myclasses[i]->toString() << endl;
		}
	}
	cout << found << " classes found.\n";
}

void CardManager::Filter(){
    int check = 0;
    cout << ">> by grade(1) or by credit(2)? > ";
    cin >> check;

//특정 등급을 가진 내 과목만 출력
    if(check == 1){
        string grade;
        cout << ">> Enter a grade > ";
        cin >> grade;

//cout << "입력받은 grade " << grade <<endl;
        for(int i=0; i<count; i++){
            if(myclasses[i]->getGrade().compare(grade) == 0){
                cout << myclasses[i]->toString() <<endl;
            }
        }
    } 
    else if(check == 2){      //특정 학점에 해당되는 과목만 출력
        double credit;
        cout << ">> Enter a credit > ";
        cin >> credit;

        for(int i=0; i<count; i++){
            if(myclasses[i]->getCredit() == credit){
    //cout << "check1\n";
                cout << myclasses[i]->toString() << endl;
            }
        }
    }
}

void CardManager::Save(){
    
    //1. 내 수강리스트의 과목코드, 등급파일 (간추린거)
	ofstream file("mycard.txt");	//파일을 쓰기 모드로 열기. 
	if(file.is_open()){		//파일이 정상적으로 열렸으면
        for(int i=0; i<count; i++)
		    file << myclasses[i]->getCode() << " " << myclasses[i]->getGrade() << endl;

		file.close();
	} 
	
    //2. List메뉴출력 내용 저장된 파일 (1번 실행시 나오는 화면)
	/* 현재까지 바뀐 최신 과목 정보들을 classes.txt파일에 업데이트 한다. */ 
	ofstream filee("report.txt");
	if(filee.is_open()){		//파일이 정상적으로 열렸으면
		for(int i = 0; i <count ; i++){
			filee << myclasses[i]->toString() << endl;
		}
		filee.close();
	}
    

    cout << "mycard.txt and report.txt saved." <<endl;
}
