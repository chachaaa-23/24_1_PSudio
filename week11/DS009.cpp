/*
Programming Studio DS009
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findRoom(int persons[5]); 
void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc);

int main(){
	string mnames[10]; // names of all male students (max. 10)
	string wnames[10]; // names of all female students (max. 10)
	int mroom[10];		// room numbers assigned all male students
	int wroom[10];		// room numbers assigned all female students
	int person[2][5]={0};   // number of persons assgined to all rooms (two floors & each five rooms) 
	int mcount=0, wcount=0; // number of all persons (male, female)
	int menu;

	srand(time(0));
	cout << "===========================================" << endl;
	cout << "생활관 호실 배정 프로그램" << endl;
	cout << "===========================================" << endl;
	while(1){
		cout << "메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ";
		cin >> menu;
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				cout << "정원 초과입니다. 등록불가!" << endl;
				continue;
			}
			cout << "학생 이름은? > ";
			cin >> mnames[mcount];
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			cout <<  mnames[mcount] << " 학생 " << mroom[mcount] << "호실 배정되었습니다." << endl;
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				cout << "정원 초과입니다. 등록불가!" << endl;
				continue;
			}
			cout << "학생 이름은? > ";
			cin >> wnames[wcount];
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			cout <<  wnames[wcount] << " 학생 " << wroom[wcount] << "호실 배정되었습니다." << endl;
			wcount++;
		}
	}

	cout << "===========================================" << endl;
	cout << "생활관 호실 배정 결과는 다음과 같습니다." << endl;
	cout << "===========================================" << endl;
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}
//한 층에 5개의 호실. 2인1실. 1층은 남학생, 2층은 여학생. - 남여 구분된 변수로 애초애 들어온다. 

int findRoom(int persons[5]){
/* 5개 호실 중 빈 베드가 있는 방을 랜덤으로 찾아낸다. (두명 모두 배정된 호실을 배정하면 안됨.)
    5개의 호실 중 persons[]배열이 2가 아닌 애들 중에서 1개를 랜덤으로 뽑는다. 

    1~5까지의 숫자 중 persons 배열에 1,2가 들어있는 애들만 해당된다. 
    2가 들어있는 배열이 있다면 그 번호를 저장하는 배열을 만들어서 거기에 넣는다. 
    그 배열의 번호는 랜덤으로 나오면, 다시 돌리라고 한다.
    반복문을 통해 계산, 
    없으면 -1 return
*/ 
    int used[5] ={0};
    //1. 두명사는 방 체크
    for(int i=0; i<5; i++){
        if(persons[i] >= 2)  //두명 사는 방이라고 체크한다. 
            used[i]=1;  //0=들어와도 됨. 1=안됨, 
    }

    int randomNum=0;

    int allUsing = true;
    //2. 모든 방 사용중인지 체크
    for(int i=0; i<5; i++){
        if(used[i] ==0 ){
            allUsing = false;
            break;
        }
    }
    if(allUsing == true){
        return -1;
    }else{
    //3. 
        while(1){
            randomNum = rand()%5 +1;
            if(used[randomNum] == 0 )   //두명 사는 방이 있고
                break;
        }
        return randomNum;
    }
}

void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc){
/*     배정결과 출력- 

남학생 명단(n명)
1. 이름 [호실]
...
여학생 명단 (n명)
1. 이름 [호실]

호실별 배정 명단
101호 : 사람이름
~~

 manName[10명], manRoomnum[10]
*/
    cout << "남학생 명단 (" << mc << ")\n" ;
    for(int i=0; i<mc; i++){
        cout << i+1 << ". " << mn[i] << " [" << mr[i] << "호]\n";
    }
		cout << "\n";

    cout << "여학생 명단 (" << wc << ")\n" ;
    for(int i=0; i<wc; i++){
        cout << i+1 << ". " << wn[i] << " [" << wr[i] << "호]\n";
    }
		cout << "\n";

    cout << "호실별 배정 명단\n";
    for(int i=0; i<5; i++){
        cout << 100+i+1 << " 호 : " ;
		for(int j=0; j<10; j++){
			if(mr[j] == 100+i+1)
			cout << mn[j] +" ";
		}
		cout << "\n";
    }

	for(int i=0; i<5; i++){
        cout << 200+i+1 << " 호 : " ;
		for(int j=0; j<10; j++){
			if(wr[j] == 200+i+1)
			cout << wn[j] +" ";
		}
		cout << "\n";
    }

}