// did in shopee coding assessment, [other question was parenthesis matching]
#include <bits/stdc++.h>
using namespace std;

class Node{
 public : 
 int data;
 Node * left;
 Node * right;
 Node(int d){
     data = d;
     left=NULL;
     right=NULL;
 }
};
int search(int key, int * arr, int l, int r){
    for (int i=l;i<=r;i++){
        if (arr[i]==key)
        return i;
    }
    return -1;
}
Node * buildTree(int * pre, int * in, int inStart, int inEnd, int preEnd){
      static int preStart = 0;
    if (preStart>preEnd || inStart>inEnd) return NULL;
  
    int cur = pre[preStart++];
    Node * root = new Node (cur);
    if (inStart==inEnd) return root;
    int inIndex = search(cur, in, inStart, inEnd);
    root->left = buildTree(pre, in, inStart,inIndex-1,preEnd);
    root->right = buildTree(pre, in, inIndex+1, inEnd, preEnd);
    return root;
}
void printPostOrder(Node * root){
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}
void printPreOrder(Node * root){
    if (!root) return;
        cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);

}
int main() {
    int n;
    cin>>n;
    int * pre = new int[n];
    int * in = new int[n];
    for (int i=0;i<n;i++){
        cin>>pre[i];
    }
     for (int i=0;i<n;i++){
        cin>>in[i];
    }
    Node * root = buildTree(pre, in, 0,n-1,n-1);
    printPostOrder(root);
    cout<<endl;
     printPreOrder(root);
	return 0;
}
