// compile for debugging
// g++ myselectionsort_debug.cpp -DEBUGMODE
//제일 작은 수를 앞으로 당기는 sorting

#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

void selectionSort(int *arr, int n){
    int min_i = 0;      

    for(int i = 0; i < n-1; i++){   //전체개수, 1씩 줄어드는 반복문, 마지막 하나뺴고 반복
        min_i = i;  //제일 작은 인덱스 설정
        for(int j = i+1; j < n; j++){   //현재보다 한칸 앞에있는 녀석
            if(arr[min_i] > arr[j]) min_i = j; 
    //첫번재 인덱스가 바로 뒤에 있는 녀석보다 크다면, Min_i를 해당 인덱스로 바꾸기
        }
        if(i != min_i) swap(arr[i], arr[min_i]);
        
        print(arr, n);  //결과출력

    }
}

int main(){
    int number = 0;
    cin >> number;

    int arr[number] ;
    for(int i=0; i<number; i++){
        cin >> arr[i];
    }

    print(arr, number);
    selectionSort(arr, number);
    print(arr, number);
    return 0;
}