#include <iostream>
using namespace std;
/* => 
6
10 7 8 9 1 5
*/

void print(int *arr, int n);
void quicksort(int* arr, int left, int right, int size);
int partition(int* arr, int left, int right);

int main(){
    int number = 0;
    cin >> number;
    int arr1[number] ;
    for(int i=0; i<number; i++)
        cin >> arr1[i];

    print(arr1, number);
    quicksort(arr1, 0, number-1, number);
        print(arr1, number);

    return 0;
}

//sorting hub
void quicksort(int* arr, int left, int right, int sizeForPrint){   //전체 배열, 전체 길이. 출력을 위해 전체 size 받기. 
    if(left < right){
    //마지막 인덱스 = Pivot
    int pivot = partition(arr, left, right);  //pivot을 기준으로 나눔
        print(arr, sizeForPrint);

    //배열을 pivot을 중심으로 각각 왼/오른쪽 정렬하기 (recursive)
    quicksort(arr, left, pivot-1, sizeForPrint);
    quicksort(arr, pivot+1, right, sizeForPrint);
    }

}

int partition(int* arr, int left, int right){
    //마지막을 pivot으로 잡고, 왼쪽&오른쪽 끝 비교
    int pivot = right;
    int i = left-1;
    int j = right;

    do{
        //왼쪽, pivot보다 큰 수 나오면 멈춤
        do {i++;} while( i<=right && arr[i] < arr[pivot]);
        //오른쪽, pivot보다 작은 수 나오면 멈춤
        do {j--;} while(j > left && arr[j] > arr[pivot]);
        //양 끝에서 찾은 인덱스 값이 있으면, swap
        if(i < j) std::swap(arr[i], arr[j]);
    } while(i<j);
    
//왼쪽 맨 끝값과 pivot의 자리바꾸기
    std::swap(arr[pivot], arr[i]);      //<- !! i랑 바꾼다!!!! while문 나오기 전까지 i++했기 때문에
    return j;       //pivot의 인덱스 return
}

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}

