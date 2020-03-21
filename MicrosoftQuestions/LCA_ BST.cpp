//Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). 
//You may assume that both the values exist in the tree.
Node* LCA(Node *root, int n1, int n2)
{if (!root) return NULL;
    
   //Your code here
   if ((root->data>=n1 && root->data<=n2) ||(root->data<=n1 && root->data>=n2)) {
       return root;
   }
   else if (root->data>= n1 && root->data>=n2){
       return LCA(root->left, n1, n2);
   }
   else  return LCA(root->right, n1,n2);
}
