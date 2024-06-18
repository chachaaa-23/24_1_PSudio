#include <iostream>
#include<string>
using namespace std;
/* 문장 앞뒤 공백 제거
    문장 입력받기. 
    공백과 탭키가 아닌 문자열이 나올때까지 루프.
        위같은 문자열이 나오는 순간부터 따로 만든 변수에 넣기. 
        어떤 문자열 이후로 문자입력 없이 white space면,
            마지막 문자열까지만 넣기. 
*/

string ltrim(string str);
string rtrim(string str);

int main(){
    //문장 입력
    string sentence;
    getline(cin, sentence);

    //공백 제거
    string newSentence = ltrim(sentence);
    newSentence = rtrim(newSentence);

    cout << newSentence <<endl;
    return 0;
}

/* 문자열 앞 공백제거 함수
find_first_not_of() 사용: 지정된 문자 집합에 속하지 않는 첫 번쨰 문자의 인덱스 반환. 
erase() : 문자열에서 원하는 문자를 지우기. 시작 위치, 지울 크기. 
erase(0, find_first_not_of( " \t" );
*/

string ltrim(string str){   //문자열 앞 공백제거 함수
/*
    cout << "str[0] : \"" << str[0] << "\"\n";
    if( (str[0] != ' ' ) || (str[0] != '\t' ) ){   //앞에 공백이 없다면
        cout << "앞공백 없음! 그냥 문자열 리턴\n";
        return str;
    }
    */

    string newString;
    str.erase(0, str.find_first_not_of(" \t"));
    //cout << "첫 글짜 지운 str : " << str <<endl;
 
    return str;
}//str.find_first_not_of(' ' || '\t' ) = 괄호 안에 해당하는 문자들을 찾는다. 

string rtrim(string str){   //문자열 뒤 공백제거 함수
/*
    cout << "str[str.length()-1] : \"" << str[str.length()-1] << "\"\n";

    if((str[str.length()-1] != ' ') || (str[str.length()-1] != '\t' ) ){     //뒤에 공백이 없다면,
        cout << "뒷공백 없음! 그냥 문자열 리턴\n";
        return str;
    }
    */
   
    str.erase(str.find_last_not_of(" \t")+1, str.length()-1 );

    //cout << "마지막 글짜 지운 str : " << str <<endl;
    return str;
}