//int type 숫자관리 스택 테스트
#include <iostream>
#include <fstream>
#include "MyStack.h"
using namespace std;
#define MAXSIZE 100

/*
 1. 파일로부터 한 학생의 GPA와 이름 하나씩 가져오기 (각각 나눠서 담겨온다.)
    파일의 한 줄, 학점과 이름을 각각 읽는다. 
 2. 현재까지 가장 높은 GPA와 비교하여 다음과 같은 작업 수행
    
 2-1. 새로 가져온 것이 더 높은 GPA다 - stack의 현재 element를 모두 지우고(clear), 
    학생의 이름을 Push한다. 높은 GPA는 따로 저장한다. 
 2-2. 같은 GPA다 - 스택에 학생의 이름 Push.
 2-3. 낮은 GPA다 - 무시하고 다음 파일내용 읽기. 

 3. 더 이상 읽을 것 없으면, 현재가장 높은 GPA 와 stack에 들어있는 이름들 출력.

=> stack에는 string type으로 바꿔서 넣어야겠네..
*/
int main(){
    //cout << "-----debug   메인 파일 실행!" <<endl;
    MyStack mystack (MAXSIZE);
    float maxGPA = 0.0;
    float testGPA = 0;
    string testName;
    ifstream file("data.txt");

    if(!file.is_open()){    //파일열 떄 오류발생
        cout << "파일을 열 수 없음." <<endl;
        return 0;
    }

/* 아래 while loop조건으로 file.eof() 안 쓰는 이유
 file.eof() 은 파일의 끝을 초과하여 읽기를 "시도" 한 경우에만 true 반환.
    -> 무조건 파일 끝에 도달했다고 바로 EOF 플래그가 설정되는 건 아님. 
=> 관리하기 복잡하니까 while 조건으로 그냥 읽기 작업이 되는 경우를 조건으로 다는게 깔끔함
*/
    while( file >> testGPA >> testName ){
        //cout << "-----debug   각 줄의 GPA와 Name 읽어오기 완료!" <<endl;

        if(testGPA > maxGPA){
            mystack.initialize();
            maxGPA = testGPA;
            mystack.push(testName);
        }
        else if(testGPA == maxGPA){
            mystack.push(testName);
        }
    }
    //파일이 끝에 다다랐을 때, 조건 
    file.close();

    if(maxGPA == 0.0){      //아무것도 읽어온 게 없을 때
        cout << "파일 값 존재x" <<endl;
        return 0;
    }
    
    cout << "Top GPA: " << maxGPA << endl;
    mystack.print();

    return 0;
}