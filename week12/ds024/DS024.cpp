#include <iostream>
#include <sstream>
#include <fstream>
#define MAX 50

using namespace std;
string kname[2] = {"A+~F", "P/F"}; // String for grading

/* 수강신청 프로그램
데이터 파일에서 읽어온 교과목 목록 관리하기 (추가, 수정, 목록보기, 검색)
- 수간과목을 등록하는 과정 진행
- 변경된 교과목 목록& 내 수강과목 목록을 파일로 저장.
*/
class MyClass{	//한 과목에 다핸 정보와 매서드들.
private:
	int code;		    // class code
	string name; 	// class name
	int unit;		    // credites
	int grading;	    // grading category (1:A+~F, 2:P/F)
public:
    MyClass(int ncode, string nname, int nunit, int ngrading){	//생성자
        code = ncode; name = nname; unit = nunit; grading = ngrading;
    }
    ~MyClass();		//소멸자
    int getCode(){return code;}		//getter&setter 
    string getName(){return name;}
    int getUnit(){return unit;}
    int getGrading(){return grading;};
    void setCode(int newcode){code = newcode;}
    void setName(string newname){name = newname;}
    void setUnit(int newunit){unit = newunit;}
    void setGrading(int newgrading){grading = newgrading;}
    string toString(){		//toString, 일종의 print 함수
        stringstream sstm;
        sstm <<  "[" << code << "] " << name << " [credit " << unit << " - "+kname[grading-1] << "]";
        return sstm.str();
    }
    string toStringSave(){		//file로 save 시 사용하는 함수. 
        stringstream sstm;
        sstm << code << " " << name << " " << unit << " " << grading;
        return sstm.str();
    }
};

class MyClassManager{	//class들을 전부 다루는 manager 객체
private:
    MyClass* allclasses[MAX];	//모든 class들의 Array. 수강신청 가능한 모든 과목
    MyClass* myclasses[10];		//내가 수강신청한 과목의 Array
    int count;		//count
    int mycount;	//mycount
public:
    MyClassManager(){		//생성자
        count=0; mycount=0;
    }
    ~MyClassManager(){}		//소멸자
    int getCount(){return count;}		//getter,setter
    int getMyCount(){return mycount;}

    void loadData(string filename);		//파일 이름을 통해 데이터 읽어오기
    void printAllClasses(); // Print all class list, 모든 과목 리스트 출력
    void findClasses(string name); // Search a class by name from the list, 이름을 통해 특정 과목 찾기
    void saveAllClasses(string filename); // Save all class list, 입력받은 파일이름에다가 모든 클래스 리스트 저장

    // Functions for modifying, 구현해야 할 함수
    void addClass(); // Add a class into the list, 모든 과목들 중 하나의 선택지 추가하기. 
    void editClass(); // Modify a class in the list, 특정 과목의 정보를 수정한다. 

    // Functions for making
    void applyMyClass(); // Apply a class, 내 과목으로 수강신청하기
    void printMyClasses(); // Print my classes, 내 과목에 있는 것들 출력하기
    void saveMyClasses(string filename); // Save my classes, 입력받은 파일 이름에 나의 클래스들 저장하기.
};


int main() {
	int no;	// menu number 
    int quit = 0;
	string name;

	MyClassManager manager; // MyClassManager obj

	manager.loadData("classes.txt");

	while(!quit){
		cout << "Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n";
		cout << ">> Menu? > ";
		cin >> no;
        switch(no){
            case 1: 
			    cout << "> 1.Print All Classes\n";
	    		manager.printAllClasses();
                break;
            case 2:
			    cout << "> 2.Add a Class\n";
    			manager.addClass();
                break;
		    case 3:
    			cout << "> 3.Modify a Class\n";
	    		manager.editClass();
                break;
            case 4:
            	cout << "> 4.Search a Class\n";
			    cout << ">> Enter class name > ";
			    cin >> name;
    			manager.findClasses(name);
                break;
		    case 5:
    			cout << "> 5.Apply a class\n";
	    		manager.applyMyClass();
		    	cout << manager.getMyCount() << " classes has been applied.\n";
                break;
    		case 6:
    			cout << "> 6.My classes\n";
	    		manager.printMyClasses();
                break;
    		case 7:
    			cout << "> 7.Save\n";
	    		manager.saveMyClasses("myclasses.txt");
		    	cout << "\n> All my classes ware saved to my_classes.txt.\n";
			    manager.saveAllClasses("classes.txt");
			    cout << "\n> All of class list ware saved to classes.txt.\n";
                break;
            case 0:
                quit = 1;
                break;
		}
	}
	return 0;
}

void MyClassManager::loadData(string filename){
    string line, name;
    int code, unit, grading;
	ifstream file(filename);
	while(!file.eof()){
        if(file.eof()) break;
		file >> code >> name >> unit >> grading;
        allclasses[count] = new MyClass(code, name, unit, grading);
		count++;
	}
	file.close();
    cout << count << " classes are loaded.\n";
}

void MyClassManager::printAllClasses(){
	for (int i=0; i<count; i++){
		cout << allclasses[i]->toString() << endl;
	}
}

void MyClassManager::saveAllClasses(string filename){
	ofstream file(filename);
	for(int i=0; i<count; i++){
		file << allclasses[i]->toStringSave();
        if(i<count-1) file << endl;
	}
	file.close();	
}

void MyClassManager::findClasses(string name){
	int found = 0;
	cout << "Searching keyword: " << name << endl;
	for(int i=0; i<count; i++){
		if(allclasses[i]->getName().find(name) != string::npos){
		    cout << allclasses[i]->toString() << endl;
			found++;
		}
	}
	cout << count << " classes found.\n";
}

// You must complete these functions.

/* Add a class into the list, 모든 과목들 중 하나의 선택지 추가하기. 
	MyClass* allclasses[MAX]에 추가하기. 마지막 값은 getCount사용. 
*/ 
void MyClassManager::addClass(){
// Caution : Don't allow the duplicate class code.
// You must complete this function.
    string name;
    int code, unit, grading;
	cout << ">> code number > ";
	cin >> code;
	cout << ">> class name > ";
	cin >> name;
	cout << ">> credits > ";
	cin >> unit;
	cout << ">> grading (1: A+~F, 2: P/F) > ";
	cin >> grading;

	// You must complete this section.
	MyClass *p;		//과목 정보 담고잇는 객체 만들어서
	p->setCode(code);		//정보 넣고,
	p->setGrading(grading);
	p->setName(name);
	p->setUnit(unit);

	allclasses[count++] = p;	//주소값 연동
}

//Modify a class in the list, 특정 과목의 정보를 수정한다. 
void MyClassManager::editClass(){
	string name; 	// class name
	int unit=0;		    // credites
	int grading=0;
	int code;
	// You must complete this section.
/* 
 입력받은 코드를 가진 과목을 찾는다
 해당 과목의 정보를 입력받고, 
 그 입력받은 내용대로 추가한다. 
*/

	while(1){
		cout << ">> Enter a code of class > ";	//코드 입력
		cin >> code;

		for(int i=0; i<count; i++){
			if(code == allclasses[i]->getCode() ){
				allclasses[i]->toString();

				cout << "> Enter new class name > ";
				cin >> name;
				allclasses[i]->setName(name);

				cout << "> Enter new credits > ";
				cin >> unit;
				allclasses[i]->setUnit(unit);

				cout << "> Enter new grading(1:Grade, 2: P/F) > ";
				cin >> grading;
				allclasses[i]->setGrading(grading);

				cout << "> Modified." <<endl;
				return;
			}
		}
		cout << "> No such class." << endl;
	}
}


/* Apply a class, 내 과목으로 수강신청하기
수강신청하려는 코드 입력받고
해당되는 코드가 있으면
그 코드를 myclasses 배열에 추가. 
*/
void MyClassManager::applyMyClass(){
	int keepgoing =0;
	while(1){
		int codeForCmp=0;
		cout << ">> Enter a class code > ";
		cin >> codeForCmp;		//수강신청하려는 코드 입력받고
		
		for(int i=0; i<count; i++){
			if(codeForCmp == allclasses[i]->getCode() ){	//해당되는 코드가 있으면
			myclasses[mycount++] = allclasses[i];	//그 코드를 myclasses 배열에 추가. 
			allclasses[i]->toString();	//해당 과목 정보 출력
			mycount++;

			cout << ">> Add more?(1:Yes 2:No) > ";
			cin >> keepgoing;
			break;	//for loop exit
			}
		}
		if(keepgoing == 1)
				continue;
		if(keepgoing == 2)
			return ;
		else	
			cout << ">> No such code of class." << endl;
	}
}

// Print my classes, 내 과목에 있는 것들 출력하기
void MyClassManager::printMyClasses(){
	int creditAll=0;
	for(int i = 0; i < mycount ; i++){
		myclasses[i]->toString();
		creditAll += myclasses[i]->getUnit();
	}
	cout << "All : " << creditAll << " credits";
}

// Save my classes, 입력받은 파일 이름에 나의 클래스들 저장하기.
void MyClassManager::saveMyClasses(string filename){
	int creditAll=0;
	int gradeCount =0;
	int pfCount =0;
	/* 파일을 하나 만든다
	그 파일에 쓴다.
	파일을 닫는다.
	*/
	ofstream file(filename);	//파일을 쓰기 모드로 열기. 
	if(file.is_open()){		//파일이 정상적으로 열렸으면
		for(int i = 0; i < mycount ; i++){
			file << (i+1) + ". " << myclasses[i]->toString() <<endl;
			creditAll += myclasses[i]->getUnit();
			if(myclasses[i]->getGrading() == 1 )
				gradeCount++;
			else if(myclasses[i]->getGrading() == 2 )
				pfCount++;
		}
		file << "All : " + mycount << " classes, " << creditAll + " credits (A+~F "
		<< gradeCount + " credits, P/F " << pfCount + " credits)" << endl;

		file.close();
	}
	cout << "> All my classes were saved to " << filename << ".";

	/* 현재까지 바뀐 최신 과목 정보들을 classes.txt파일에 업데이트 한다. */
	ofstream filee("classes.txt");
	if(file.is_open()){		//파일이 정상적으로 열렸으면
		for(int i = 0; i < mycount ; i++){
			file << myclasses[i]->toStringSave() <<endl;
		}
		file.close();
	}
	cout << "> All of class list were saved to " << filename << ".";
}