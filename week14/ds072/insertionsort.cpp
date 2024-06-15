#include <iostream>
using namespace std;
// 두개씩 인덱스를 잡아 정렬하고, 이후 그 다음 값을 정렬된 인덱스 사이에 넣는것.

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

/* => 정렬된 리스트에 data 값을 비교해서 적절한 위치에 넣는 sort.
 맨 처음 두개의 인덱스 정렬.
 이후 인덱스들, 앞에 정렬된 인덱스와 값 비교해서 그 사이에 삽입한다.
 배열 끝까지 반복한다. 
*/
void insertionsort(int *arr, int n){
    int scope, max_i=0;    //초기값    
    if(n==1) return ;   //인자가 1개

    //맨 처음 2개 인덱스 정렬
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
    print(arr, n);

    for(int i=2; i<n; i++){ //전체범위 sort
        int key = arr[i];   //정렬할 값 저장 (인덱스로 옮기는 게 아니라, 값을 인덱스에 넣는 것. )
        int j = i-1;

        while(j >=0 && arr[j] > key ){  //키값보다 큰 요소가 있으면
                arr[j+1] = arr[j];      //오른쪽으로 옮기기
                j--;
        }
        arr[j+1] = key;     //key값이 들어갈 자리 찾을 시 값 넣기
        print(arr, n);
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
    insertionsort(arr, number);

    return 0;
}