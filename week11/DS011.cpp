#include <iostream>
using namespace std;
/*
입력하려는 숫자 개수 받기
-> new를 사용해서 동작배열을 만들어 사용. (STL 사용 x)
-> 입력하려는 숫자를 보내고, 포인터로 받아온다. 
그 숫자만큼 정수 입력
총합과 최댓값 출력

*/
int* calculate(int* numbers, int size);
int main(){
    int size =0;

    cin >> size;
    int* numbers= new int[size];    //메모리 할당. 끝나고 해제필수.
    for(int i=0; i<size; i++){
        cin >> numbers[i] ;    //값 입력받기
    }

    int* sumNMax = calculate(numbers, size); 
    
    cout << sumNMax[0] ;
    cout << sumNMax[1] <<endl;

    delete[] numbers;
    delete[] sumNMax;

    return 0;
}

//정의 계산결과 출력해주는 함수
int* calculate(int* numbers, int size){
    //합 출력
    int* output = new int[2];   //0은 sum, 1은 max
    output[0]=0;
    output[1]=0;

    for(int i=0; i< size ; i++){
        output[0] += numbers[i];
        if(numbers[i] >= output[1]){
            output[1] = numbers[i];
        }
    }
    return output;
}