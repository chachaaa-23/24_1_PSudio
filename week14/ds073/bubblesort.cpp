#include <iostream>
using namespace std;
/* => 전체 element중 가장 큰 값을 찾아서 뒤로 보내는 sort.
오름차순 정렬함수: 
    i, i+1 대소비교, 큰 것을 i+1로 보내기. 
    n까지 반복, 매 반복마다 n--.
내림차순 정렬함수: 
*/

void print(int *arr, int n);
void bubblesort_asce(int* arr, int n);
void bubblesort_desc(int* arr, int n);

int main(){
    int number = 0;
    cin >> number;

    int arr1[number], arr2[number] ;
    for(int i=0; i<number; i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    cout << "=== ascending order ===" <<endl;
    print(arr1, number);
    bubblesort_asce(arr1, number);
    cout << "=== descending order ===" <<endl;
    print(arr2, number);
    bubblesort_desc(arr2, number);

    return 0;
}

void bubblesort_asce(int* arr, int n){
    int num = n;
    while(n > 1){
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
        }
        n--;
        print(arr, num);
    }
}

void bubblesort_desc(int* arr, int n){
    int num = n;
    while(n > 1){
        for(int i=0; i<n-1; i++){
            if(arr[i] < arr[i+1]) swap(arr[i], arr[i+1]);
        }
        n--;
        print(arr, num);
    }
}

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] " ;
    cout << endl;
}