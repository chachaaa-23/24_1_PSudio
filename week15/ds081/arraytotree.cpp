// github 용
#include <iostream>
#include <queue>
using namespace std;
 
class TreeNode {
public:    
    int val;    //저장할 int 값. 
    TreeNode *left, *right;     //왼/오른쪽 자식
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
 
TreeNode* buildTree(int *nums, int size) {  
    //tree만들기. queue를 통해 
    if (nums == NULL) return NULL;
    
    TreeNode* root = new TreeNode(nums[0]); //nums = root 값. 
    queue<TreeNode*> q; //빈 큐를 만들어서
    q.push(root);       //root 노드를 넣는다
    int i = 1;
    while (i < size) {
        TreeNode* curr = q.front();     //현재 순회중인 노드를 q의 front로 설정.
        q.pop();    //q, 하나 빼기
        if (i < size) {
            curr->left = new TreeNode(nums[i++]);   //현재 순회중인 노드의 왼쪽 값 넣기
            q.push(curr->left); //q에 값 넣을것 저장
        }
        if (i < size) {          
            curr->right = new TreeNode(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
 
void printInOrderTree(TreeNode* root) {
    if (!root) return;

    printInOrderTree(root->left);
    
    if(root->val != 0){
        cout << root->val << " ";
    }
    
    printInOrderTree(root->right);
}
 
int main() {
//원하는 개수의 숫자들 입력받아
//그 순서대로 노드를 가진 binary tree 만들고
//그 tree를 Inorder traversal 한 결과 출력하기. 
//-> inorder traversal : 왼쪽 subtree 중위순회- 루트 방문- 오른쪽 subtree 중위순회
//      왼쪽의 가장 끝 부분으로 재귀적으로 이동, nullptr면 멈추기, 현재값 출력하고, 오른쪽 children으로 이동

    int num = 0;
    cin >> num;

    int nums[num];
    for(int i=0; i<num; i++){
        cin >> nums[i];
    }
        
    int size = sizeof(nums) / sizeof(int);
    TreeNode* root = buildTree(nums,size);
    printInOrderTree(root);
    cout <<endl;
    return 0;
}