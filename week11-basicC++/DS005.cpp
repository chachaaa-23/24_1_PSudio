#include <iostream>
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower, std::isalpha
using namespace std;
/*
알파벳 개수 세기
1. 영어로 된 문장 입력 (50자 내)
2. 문장 속 공백과 알파벳 개수, 대소문자 구분없이 A-Z 순서대로 표시
    루프 돌면서 각 char의 개수 세기. 
    해당되는 문자열의 값 출력하기. 0이 아니면 출력.
*/

int main(){
    int alphabet[26] = {0}; // 알파벳 빈도를 저장하는 배열
    int blank = 0; // 공백 문자의 개수를 저장하는 변수 
    string sentence;

    getline(cin, sentence);
    //cout << "문장 입력받기 완료!\n";
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper );

    for(int i=0; i< sentence.length() ; i++){
        //cout << sentence[i] << "계산\n";
        //1. 입력받은 게 존재하고, 공백인 경우
        //2. 입력받은 게 존재하고, 알파벳인 경우
        //2-1. 해당되는 알파벳 배열 ++.
        if(sentence[i] == ' '){
        blank++;
        }else if( std::isalpha(sentence[i]) ){
            int index = sentence[i] - 'A' ;
            //cout << "   index: "<< index << endl;
            alphabet[ index ]++;
            //cout << "   alphabet[index]: " << alphabet[index] <<endl;
        }
    }

    if(blank > 0)
        cout << "blank: " << blank << endl;

    for(int i=0 ;i< 26; i++){
        if(alphabet[i] != 0)
            cout << static_cast<char>('A'+i) << " : " << alphabet[i] << endl ;
    }

    return 0;
}