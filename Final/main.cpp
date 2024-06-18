#include "card.h"
#include "cardManager.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map<string, Card*> allclasses;
void loadData(string filename);
void printAllClasses();

int main(){
	int no;	// menu number 
    int quit = 0;

    loadData("classes.txt");
	string name;

	CardManager manager; 
//1-6번 구현과 비슷하게 어떤 객체를 만드는 작업일듯!
//vector(stack, LIFO)와 Map(hashmap, key-value)

	while(!quit){
		cout << "[Menu] 1.View 2.Add 3.Change 4.Sort 5.Search 6.Load 7.All 0.Quit\n";
		cout << ">> Menu? > ";
		cin >> no;
        switch(no){
            case 1: 
			    cout << "> 1. All My Score Cards\n";
	    		manager.printAll();
                break;
            case 2:
			    cout << "> 2.Add a New Score Card\n";
    			manager.addCard();
                break;
		    case 3:
    			cout << "> 3.Change a Grade\n";
	    		manager.editCard();
                break;
		    case 4:
    			cout << "> 4.Sort by Code\n";
	    		manager.sortByCode();
		    	cout << "Sorted.\n";
                break;
            case 5:
            	cout << "> 5.Search a Class\n";
			    cout << ">> Enter class name > ";
			    cin >> name;
    			manager.findCards(name);
                break;
		    case 6:
    			cout << "> 6.Load My Cards\n";
	    		manager.loadCards("mycard.txt");
                break;
    		case 7:
    			cout << ">>7.All Classes\n";
                printAllClasses();
                break;
            case 0:
                quit = 1;
                break;
		}
	}
	return 0;
}

void loadData(string filename){
    string line, name, code;
    int credit, count=0;
	ifstream file(filename);	//파일객체 생성
	while(!file.eof()){		//파일 끝에 다다르지 않았다면
        if(file.eof()) break;
		file >> code >> name >> credit;	//하나씩 입력받고
        allclasses[code] = new Card(code, name, credit);	//Map에 저장
		count++;
	}
	file.close();
    cout << count << " classes are loaded.\n";
}

void printAllClasses(){
    map<string, Card*>::iterator iter;
    for (iter = allclasses.begin(); iter != allclasses.end(); ++iter) {
        cout << iter->second->toStringShort() << endl;
    }
}