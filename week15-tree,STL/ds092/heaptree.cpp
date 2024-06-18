#include <iostream>
#include <vector>
using namespace std;

int sizee = 0;  // 현재 힙의 크기

void printArray(int* arr, int size) {  // 결과 출력 시 사용
    cout << "==> Heap : ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insertKey(int arr[], int value, int N) {  // 키값 새롭게 넣는 함수
    if (sizee == N) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // 새로운 값을 힙의 마지막에 삽입
    int i = sizee;
    arr[i] = value;
    sizee++;

    // 힙 성질을 유지하기 위해 부모와 비교하여 필요시 교환
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {  // 하극상 (자식이 부모보다 크다)
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

#ifdef _DEBUG
    printArray(arr, sizee);
#endif
}

void maxHeapify(int arr[], int rootindex) {  // 힙의 성질을 유지하기 위한 함수
    int largest = rootindex;
    int left = 2 * largest + 1;
    int right = 2 * largest + 2;

    if (left < sizee && arr[left] > arr[largest])  // 왼쪽 자식이 더 클 경우
        largest = left;
    if (right < sizee && arr[right] > arr[largest])  // 오른쪽 자식이 더 클 경우
        largest = right;
    if (largest != rootindex) {  // 자식 중 더 큰 값이 있을 경우
        swap(arr[rootindex], arr[largest]);
        maxHeapify(arr, largest);  // 재귀적으로 힙 정리
    }
}

void deleteKey(int arr[]) {
    if (sizee == 0) {
        cout << "\nCould not deleteKey\n";
        return;
    }

#ifdef _DEBUG
    cout << "=> Delete " << arr[0] << endl;  // 루트 노드를 삭제
#endif

    arr[0] = arr[sizee - 1];  // 마지막 노드를 루트로 이동
    sizee--;  // 힙 크기 감소

    maxHeapify(arr, 0);  // 힙 성질 유지

#ifdef _DEBUG
    printArray(arr, sizee);
#endif
}

/* 배열에서 k번째 가장 큰 수 찾기
   정수의 개수와 n번째로 큰 수 찾을것 입력받고, 변수들에 저장하기
   max heap을 통해 각 숫자 입력
   k-1번 pop하고, top을 출력한다! 
*/
int main() {
    int numToPrint = 0;
    int num;
    int length = 0;
    cin >> length;
    cin >> numToPrint;

    int arr[length];
    for (int i = 0; i < length; i++) {
        cin >> num;
        insertKey(arr, num, length);
    }

    for (int i = 0; i < numToPrint - 1; i++) {
        deleteKey(arr);
    }

    cout << "결과 : " << arr[0] << endl;

    return 0;
}
