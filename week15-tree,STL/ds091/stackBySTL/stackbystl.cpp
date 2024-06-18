#include <iostream>
#include <string>
#include <stack>        //STL stack사용, 메모리할당 필요 x
using namespace std;
//커서를 왼쪽으로 이동 = 현재 커서 위치 기준 오른쪼긍로 이동한다는 뜻! 이 상태에서 다시 오른쪽으로 움직이면, 기존에 있었던게 POp하고 나오는 느낌..

int main() {
    string input;  // 사용자로부터 입력받은 문자열을 저장할 변수

    stack<char> leftStack ;  // 커서 왼쪽 부분을 저장할 스택
    stack<char> rightStack;  // 커서 오른쪽 부분을 저장할 스택

    while (true) {
        cin >> input;  // 사용자로부터 입력을 받음

        if (input == "q") {  // 'q' 입력 시 프로그램 종료
            break;
        }

        for (char c : input) {  // 입력된 문자열을 한 문자씩 처리..
            if (c == '<') {  // '<' 입력 시 커서를 왼쪽으로 이동 = 커서기준 왼쪽에 있던 애를 오른쪽으로 보낸다는 느낌, 오른쪽 Stack에 저장..
                if (!leftStack.empty()) {  // 왼쪽 스택이 비어있지 않다면
                    rightStack.push(leftStack.top());  // 왼쪽 스택의 top을 pop하여 오른쪽 스택에 push. 이때 top을 먼저한 뒤
                    leftStack.pop();        //pop을 통해 제거!
                }
            } else if (c == '>') {  // '>' 입력 시 커서를 오른쪽으로 이동
                if (!rightStack.empty()) {  // 오른쪽 스택이 비어있지 않다면
                    leftStack.push(rightStack.top());  // 오른쪽 스택의 top을 pop하여 왼쪽 스택에 push
                    rightStack.pop();
                }
            } else {  // 알파벳이나 숫자 입력 시
                leftStack.push(c);  // 왼쪽 스택에 push
            }
        }

        // 왼쪽 스택의 모든 문자를 저장할 문자열
        string result;
        char tmp;

        // 왼쪽 스택을 순서대로 pop하여 결과 문자열에 추가
        //-> 이때 LIFO 이므로 일단 오른쪽 Stack에 옮겨놓고 (어짜피 긑에서부터 들어간다, 오른쪽 커서는 자동으로 맨 마지막 글이 된다.) 
        //   그 오른쪽 stack을 pop한다..
        while (!leftStack.empty()) {
            rightStack.push(leftStack.top()); //일단옮겨놓고
            leftStack.pop();
        }
        while (!rightStack.empty()) {
            result += rightStack.top();    //진짜결과 pop
            rightStack.pop();
        }

        // 오른쪽 스택에 남아있는 문자를 저장할 문자열
        string temp;

        // 오른쪽 스택을 순서대로 pop하여 결과 문자열에 추가
        while (!rightStack.empty()) {
            temp = rightStack.top() + temp;
            rightStack.pop();
        }

        // 전체 결과 문자열 출력
        cout << "=> " << result + temp << endl;

        // 스택 초기화
        while(!leftStack.empty()) leftStack.pop();
        while(!rightStack.empty()) rightStack.pop();
    }

    return 0;
}
