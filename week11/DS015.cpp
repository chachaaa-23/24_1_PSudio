#include <iostream>
#include<string>
using namespace std;
/* 마지막 단어의 길이 구하기
- 구조체 2개이상 사용
- 함수 2개 이상 제작해 사용
- 함수 파라미터로 reference type 사용.

공백과 탭키 포함된 문자열 입력받기
전체문장 앞뒤의 공백과 탭키 제거
 < 마지막 단어의 길이를 구하기. >
    > 정렬된 문장을 공백을 기준으로 단어별로 끊는다.
    > 각각 끊은 단어들을 array에 넣는다. 

 가장 마지막 array를 파라미터로 받아, 결과를 출력한다. 
    > 가장 마지막 array에 있는 문자열의 가장 끝 문자를 반환한다. 
*/
struct StringInfo {     //string 정보 담은 struct
    string original;
    string trimmedLast;
    int lastWordLength;
};

string ltrim(string str);
string rtrim(string str);
//마지막 단어와 문자 구하는 함수
void processLastWord(StringInfo &stringinfo); 
//결과 출력하는 함수
void printResult(StringInfo& s);

int main(){
    StringInfo stringinfo;

    //문장 입력
//    string sentence;
    getline(cin, stringinfo.original);

    //공백 제거
    string newSentence = ltrim(stringinfo.original);
    newSentence = rtrim(newSentence);
    stringinfo.original = newSentence;

    //white space 없는 문장에서, 마지막 단어 찾기. 
    processLastWord(stringinfo);

    //결과 출력하기. 
    printResult(stringinfo);
    return 0;
}

/* 문자열 앞 공백제거 함수
find_first_not_of() 사용: 지정된 문자 집합에 속하지 않는 첫 번쨰 문자의 인덱스 반환. 
erase() : 문자열에서 원하는 문자를 지우기. 시작 위치, 지울 크기. 
erase(0, find_first_not_of( " \t" );
*/

string ltrim(string str){   //문자열 앞 공백제거 함수
    str.erase(0, str.find_first_not_of(" \t")); 
    return str;
}
string rtrim(string str){   //문자열 뒤 공백제거 함수
    str.erase(str.find_last_not_of(" \t")+1, str.length()-1 );
    return str;
}
/*white space 없는 문장에서, 마지막 단어 찾기. 
-> 맨 마지막에 있는 공백부터 끝까지 단어 자르기
이를 구조체에 넣고 반환하기. 

*/
void processLastWord(StringInfo& stringinfo) {
    string str = stringinfo.original;
    size_t lastSpacePos = str.find_last_of(" \t");

    if (lastSpacePos != string::npos) {
        stringinfo.trimmedLast = str.substr(lastSpacePos + 1);
    } else {
        stringinfo.trimmedLast = str;
    }

    stringinfo.lastWordLength = stringinfo.trimmedLast.length();
}

/*결과출력*/
void printResult(StringInfo& s){
    cout << s.trimmedLast<< "가 마지막 단어이므로";
    cout << s.lastWordLength << "이다.\n";
}